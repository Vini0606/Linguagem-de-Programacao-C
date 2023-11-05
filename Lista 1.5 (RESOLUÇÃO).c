#include <stdio.h>
#define N 6
#define M 10
#define S 100

int main(void) {

int questao;
int A1[N];
int A3[S];
float A2[M];
int A4[M];
int A5[M];
float A5_desvios[M];
float media;
float variancia;
float desvio_padrao;
int A4_ig[M];
int soma1;
int soma5 = 0;
float soma2 = 0;
int i;
int p;
int i2;
int cont = 0;

while (questao != 0) {
  printf("\n\nEscolha o numero da questão:\n\nQuestão 1\nQuestão 2\nQuestão "
           "3\nQuestão 4\nQuestão 5\n0 para Sair\n\n");
  scanf("%d", &questao);
    switch (questao) {

    case 1:
      for (i = 0; i != N; i++) {
        printf("\nDigite um valor para o vetor: ");
        scanf(" %d", &A1[i]);
      }

      soma1 = A1[0] + A1[1] + A1[5];
      printf("\nValor da soma: %d\n", soma1);
      A1[4] = 100;

      for (i = 0; i < N; i++) {

        printf("\n%d", A1[i]);
      }
      break;

    case 2:
      for (i = 0; i < M; i++) {
        printf("Digite um valor real para o vetor: ");
        scanf("%f", &A2[i]);
      }

      for (i = 0; i < M; i++) {
        if (A2[i] < 0) {
          cont += 1;
        } else {
          soma2 += A2[i];
        }
      }

      printf("\nExistem %d numeros negativos", cont);
      printf("\nSoma dos positivos é igual a %f", soma2);

      break;

    case 3:

    cont = 0;
    
    for (i = 7; cont < S; i++) {
      if (i % 7 == 0 && i > 6) {
        A3[cont] = i;
        cont += 1;
      }
    }

    for (i = 0; i < S; i++) {
      printf("%d\n", A3[i]);
    }
    
    break;

    case 4:

    for (i = 0; i < M; i++) {
      printf("Digite um valor inteiro para o vetor: ");
      scanf("%d", &A4[i]);
    }

    cont = 0;
      
    for (i = 0; i < M; i++) {
      for (p = 0; p < M; p++) {
        if (i != p) {
          if (A4[i] == A4[p]) {
            printf("\n%d", A4[i]);
          }
        }
      } 
    }
    
    break;

    case 5:

    for (i = 0; i < M; i++) {
      printf("Digite um valor inteiro: ");
      scanf("%d", &A5[i]);
    }

    for (i = 0; i < M; i++) {
      soma5 += A5[i];
    }

    media = soma5/10;

    for (i = 0; i < M; i++) {
      A5_desvios[i] = A5[i] - media;
      A5_desvios[i] = A5_desvios[i] * A5_desvios[i];
    }

    for (i = 0; i < M; i++) {
      variancia += A5_desvios[i];
    }

    variancia /= 10;
    desvio_padrao = variancia * variancia;

    printf("O desvio padrão é: %f", desvio_padrao);
      
    break;
    
    }
  }

  return 0;
}