#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int* func_n(int);
char* inversor(const char*);

int main(void) {
    int opcao;

    while (1) {
        printf("\nEscolha uma opção:\n");
        printf("1. Testar func_n\n");
        printf("2. Testar inversor de string\n");
        printf("0. Sair\n");

        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                {
                    int n;
                    printf("Digite o tamanho do array de inteiros: ");
                    scanf("%d", &n);

                    int* ptr = func_n(n);

                    if (ptr == NULL) {
                        printf("Erro na alocação de memória.\n");
                    } else {
                        printf("Memória alocada para o array de inteiros com tamanho %d no endereço: %p\n", n, (void*)ptr);
                        free(ptr);
                    }
                }
                break;
            case 2:
                {
                    char str[100];
                    printf("Digite uma string: ");
                    scanf("%s", str);

                    char* invertida = inversor(str);

                    if (invertida != NULL) {
                        printf("String original: %s\n", str);
                        printf("String invertida: %s\n", invertida);
                        free(invertida);
                    } else {
                        printf("Erro na alocação de memória para a string invertida.\n");
                    }
                }
                break;
            case 0:
                printf("Saindo...\n");
                return 0;
            default:
                printf("Opção inválida. Tente novamente.\n");
        }
    }

    return 0;
}

int* func_n(int n) {
    int* ptr = (int*)malloc(sizeof(int) * n);
    return ptr;
}

char* inversor(const char* str) {
    int tam = strlen(str);
    char* invertida = (char*)malloc((tam + 1) * sizeof(char));

    if (invertida == NULL) {
        return NULL;
    }

    int indice_origem = tam - 1;
    int indice_destino = 0;

    while (indice_origem >= 0) {
        invertida[indice_destino] = str[indice_origem];
        indice_origem--;
        indice_destino++;
    }

    invertida[indice_destino] = '\0';

    return invertida;
}
