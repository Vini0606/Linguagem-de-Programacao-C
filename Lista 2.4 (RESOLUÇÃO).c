#include <stdio.h>

int main(void) {
    
  
    FILE *fp_facul;
    FILE *fp_fam;
    FILE *fp_facul_fam;
    char nome[30];

    // Questão 1
    // Carregar Ponteiros com Endereços de Arquivos
    fp_facul = fopen("arquivo_facul.txt", "r");
    if (fp_facul == NULL) {
        printf("Problema ao abrir arquivo_facul.txt\n");
        return 1;
    }

    fp_fam = fopen("arquivo_fam.txt", "r");
    if (fp_fam == NULL) {
        printf("Problema ao abrir arquivo_fam.txt\n");
        fclose(fp_facul);
        return 1;
    }

    fp_facul_fam = fopen("arquivo_facul_fam.txt", "w");
    if (fp_facul_fam == NULL) {
        printf("Problema ao abrir arquivo_facul_fam.txt\n");
        fclose(fp_facul);
        fclose(fp_fam);
        return 1;
    }

    // Escrever Valores de arquivo_facul em arquivo_facul_fam
    printf("Nomes em arquivo_facul:\n");
    while (fgets(nome, sizeof(nome), fp_facul) != NULL) {
        printf("%s", nome);
        fputs(nome, fp_facul_fam);
    }

    // Escrever Valores de arquivo_fam em arquivo_facul_fam
    printf("\n\nNomes em arquivo_fam:\n");
    while (fgets(nome, sizeof(nome), fp_fam) != NULL) {
        printf("%s", nome);
        fputs(nome, fp_facul_fam);
    }

    // Fechar Arquivos
    fclose(fp_facul);
    fclose(fp_fam);
    fclose(fp_facul_fam);

  // Questão 2
  FILE *fp;
  char c;
  int contagem[26] = {0};

  // Abrir Arquivo
  fp = fopen("arquivo.txt", "r");
  if (fp == NULL) {
      printf("Erro ao abrir o arquivo\n");
      return 1;
  }

  // Contar Letras
  while ((c = fgetc(fp)) != EOF) {
      if (isalpha(c)) { // Verifica se é uma letra
          c = toupper(c); // Converte para maiúsculas
          if (c >= 'A' && c <= 'Z') { // Verifica se está no intervalo correto
              contagem[c - 'A']++; // Incrementa a contagem
          }
      }
  }

  // Imprimir contagem
  for (int i = 0; i < 26; i++) {
      if (contagem[i] > 0) {
          printf("%c: %d\n", 'A' + i, contagem[i]);
      }
  }

  // Fechar Arquivo
  fclose(fp);

  // Questão 3
  
  FILE *fp1;
  char numero[9];
  char nome1[30];

  // Abrir arquivo para escrita
  fp1 = fopen("registros.txt", "w");
  if (fp == NULL) {
      printf("Problema ao abrir o arquivo.\n");
      return 1;
  }

  while (1) {
      // Solicitar nome
      printf("Digite o nome: ");
      if (fgets(nome1, sizeof(nome), stdin) == NULL) {
          break;  // Entrada encerrada
      }

      // Remover a quebra de linha da entrada do nome
      nome[strcspn(nome1, "\n")] = '\0';

      // Verificar se a entrada é um número de telefone válido
      printf("Digite o telefone (8 números): ");
      if (fgets(numero, sizeof(numero), stdin) == NULL) {
          break;  // Entrada encerrada
      }

      // Remover a quebra de linha da entrada do número
      numero[strcspn(numero, "\n")] = '\0';

      // Verificar se o número tem exatamente 8 dígitos
      if (strlen(numero) == 8) {
          // Escrever no arquivo
          fprintf(fp1, "Nome: %s; Numero: %s\n", nome1, numero);
      } else {
          printf("Número de telefone inválido. Deve conter exatamente 8 dígitos.\n");
      }
  }

  // Fechar o arquivo
  fclose(fp1);
  
  return 0;

}
