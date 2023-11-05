#include <stdio.h>
#include <math.h>

// Protótipos das funções
int maior(int a, int b);
int Bissexto(int ano);
int conversor(int horas, int minutos, int segundos);
float calculo_media(float nota1, float nota2, float nota3, char letra);
void partes(float num, int *inteiro, float *fracionario);
void area_esfera(float raio, float *volume, float *area);

int main(void) {
    int opcao;

    while (1) {
        printf("\nEscolha uma opção:\n");
        printf("1. Maior\n");
        printf("2. Ano Bissexto\n");
        printf("3. Conversor de Horas, Minutos e Segundos para Segundos\n");
        printf("4. Cálculo de Média\n");
        printf("5. Dividir um Número em Parte Inteira e Fracionária\n");
        printf("6. Cálculo de Área e Volume de uma Esfera\n");
        printf("0. Sair\n");

        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
            {
                int num1, num2;
                printf("Digite dois números: ");
                scanf("%d %d", &num1, &num2);
                int result = maior(num1, num2);
                printf("O maior número é: %d\n", result); // Adicione o "result" aqui
            }
            break;
            case 2:
                {
                    int ano;
                    printf("Digite um ano: ");
                    scanf("%d", &ano);
                    if (Bissexto(ano)) {
                        printf("%d é um ano bissexto.\n");
                    } else {
                        printf("%d não é um ano bissexto.\n");
                    }
                }
                break;
            case 3:
            {
                int horas, minutos, segundos;
                printf("Digite as horas, minutos e segundos: ");
                scanf("%d %d %d", &horas, &minutos, &segundos);
                int totalSegundos = conversor(horas, minutos, segundos);
                printf("O tempo em segundos é: %d\n", totalSegundos);
            }
            break;
            case 4:
                {
                    float nota1, nota2, nota3;
                    char letra;
                    printf("Digite três notas: ");
                    scanf("%f %f %f", &nota1, &nota2, &nota3);
                    printf("Escolha A (Aritmética) ou P (Ponderada): ");
                    scanf(" %c", &letra);
                    float media = calculo_media(nota1, nota2, nota3, letra);
                    if (media == -1) {
                        printf("Opção inválida. Escolha A ou P.\n");
                    } else {
                        printf("A média é: %.2f\n", media);
                    }
                }
                break;
            case 5:
                {
                    float numero;
                    int inteiro;
                    float fracionario;
                    printf("Digite um número real: ");
                    scanf("%f", &numero);
                    partes(numero, &inteiro, &fracionario);
                    printf("Parte Inteira: %d\n", inteiro);
                    printf("Parte Fracionária: %.2f\n", fracionario);
                }
                break;
            case 6:
                {
                    float raio, volume, area;
                    printf("Digite o raio da esfera: ");
                    scanf("%f", &raio);
                    area_esfera(raio, &volume, &area);
                    printf("Volume da esfera: %.2f\n", volume);
                    printf("Área da superfície da esfera: %.2f\n", area);
                }
                break;
            case 0:
                printf("Saindo...\n");
                return 0;
            default:
                printf("Opção inválida. Tente novamente.\n");
        }
    }
}

int maior(int a, int b) {
  if (a > b) {
    return a;
  } else {
    return b;
  }
}

int Bissexto(int ano) {
    if (ano % 4 == 0 && (ano % 100 != 0 || ano % 400 == 0)) {
        return 1; // é bissexto
    } else {
        return 0; // não é bissexto
    }
}

int conversor(int horas, int minutos, int segundos) {
  int totalSegundos = 0;
  totalSegundos += horas * 3600;
  totalSegundos += minutos * 60;
  totalSegundos += segundos;
  return totalSegundos;
}

float calculo_media(float nota1, float nota2, float nota3, char letra) {
  float media;

  if (letra == 'A') {
    media = (nota1 + nota2 + nota3) / 3.0;
  } else if (letra == 'P') {
    media = (5.0 * nota1 + 3.0 * nota2 + 2.0 * nota3) / 10.0;
  } else {  // letra inválida
    media = -1.0;
  }

  return media;
}

void partes(float num, int *inteiro, float *fracionario) {
  *inteiro = (int) num;
  *fracionario = num - *inteiro;
}

void area_esfera(float raio, float *volume, float *area) {
  const float pi = 3.141592;
  *volume = (4 * pi * raio * raio * raio) / 3;
  *area = 4 * pi * raio * raio;
}
