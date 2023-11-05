#include <stdio.h>

int strf(char*, char*);

int main(void) {
    
    // Declarar Variáveis 
    int choice;
    char str1[] = "Hello";
    char str2[] = "World";
    int result = strf(str1, str2);
    int v[5] = {1, 2, 3, 4, 5};
    int *p = v;
    int i;

    while (1) {
        printf("\nEscolha uma opção:\n");
        printf("1. Questão 1\n");
        printf("2. Questão 2\n");
        printf("0. Sair\n");

        scanf("%d", &choice);

        switch (choice) {
            case 1:
                // Questão 1
                for (i = 0; i < 5; i++) {
                    if (v[i] % 2 == 0) {
                        printf("\nValor par: %d\nEndereço: %p", v[i], (void*)&p[i]);
                    }
                }
                break;
            case 2:
                // Questão 2
                if (result == 0) {
                    printf("As strings são iguais.\n");
                } else if (result == 1) {
                    printf("str1 é maior que str2.\n");
                } else {
                    printf("str1 é menor que str2.\n");
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

int strf(char* str1, char* str2) {
    if (*str1 == *str2) {
        return 0;
    }

    if (*str1 > *str2) {
        return 1;
    } else {
        return -1;
    }
}
