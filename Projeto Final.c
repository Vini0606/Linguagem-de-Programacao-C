          #include <stdio.h>
          #include <string.h>

          #define MAX_CONTATOS 30

          typedef struct {
              char nome[30];
              char telefone[30];
              char email[30];
          } Contato;

          void adicionarContato(Contato *contatos, int *totalContatos) {
              if (*totalContatos < MAX_CONTATOS) {
                  printf("-- Adicionar Contato --\n\n");
                  printf("Nome: ");
                  fgets(contatos[*totalContatos].nome, sizeof(contatos[*totalContatos].nome), stdin);
                  printf("Telefone: ");
                  fgets(contatos[*totalContatos].telefone, sizeof(contatos[*totalContatos].telefone), stdin);
                  printf("Email: ");
                  fgets(contatos[*totalContatos].email, sizeof(contatos[*totalContatos].email), stdin);
                  (*totalContatos)++;
                  printf("\nContato registrado.\n");
              } else {
                  printf("Não há mais espaço para registros.\n");
              }
              printf("--------\n");
          }

          void listarContatos(const Contato *contatos, int totalContatos) {
              if (totalContatos == 0) {
                  printf("Nenhum contato cadastrado.\n");
              } else {
                  printf("Lista de Contatos:\n");
                  for (int i = 0; i < totalContatos; i++) {
                      printf("Contato %d\n", i + 1);
                      printf("Nome: %s", contatos[i].nome);
                      printf("Telefone: %s", contatos[i].telefone);
                      printf("Email: %s", contatos[i].email);
                  }
              }
              printf("Total de registros: %d\n", totalContatos);
              printf("--------\n");
          }

          void salvarContatos(const Contato *contatos, int totalContatos, const char *nomeArquivo) {
              FILE *fp = fopen(nomeArquivo, "w");
              if (fp == NULL) {
                  printf("Erro ao abrir o arquivo para escrita.\n");
                  return;
              }
              for (int i = 0; i < totalContatos; i++) {
                  fprintf(fp, "Nome: %s", contatos[i].nome);
                  fprintf(fp, "Telefone: %s", contatos[i].telefone);
                  fprintf(fp, "Email: %s", contatos[i].email);
                  fprintf(fp, "\n\n");
              }
              fclose(fp);
              printf("Contatos salvos com sucesso.\n");
          }

          int main() {
              Contato contatos[MAX_CONTATOS];
              int totalContatos = 0;
              int opcao;
              char nomeArquivo[50];

              do {
                  printf("\nMenu:\n");
                  printf("1. Adicionar um novo contato\n");
                  printf("2. Listar todos os contatos\n");
                  printf("3. Salvar contatos em um arquivo\n");
                  printf("4. Sair\n");
                  printf("Escolha a opção: ");
                  scanf("%d", &opcao);

                  switch (opcao) {
                      case 1:
                          adicionarContato(contatos, &totalContatos);
                          break;
                      case 2:
                          listarContatos(contatos, totalContatos);
                          break;
                      case 3:
                          if (totalContatos > 0) {
                              printf("Digite o nome do arquivo: ");
                              scanf(" %49[^\n]", nomeArquivo);
                              salvarContatos(contatos, totalContatos, nomeArquivo);
                          } else {
                              printf("Nenhum contato para salvar.\n");
                          }
                          break;
                      case 4:
                          printf("Encerrando o programa.\n");
                          break;
                      default:
                          printf("Opção inválida. Tente novamente.\n");
                  }
              } while (opcao != 4);

              return 0;
          }
