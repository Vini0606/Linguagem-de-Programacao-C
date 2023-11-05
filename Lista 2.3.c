#include <stdio.h>
#include <limits.h>
#include <math.h>

struct Hora {
    int hora;
    int minuto;
    int segundo;
};

typedef struct {
    int dia;
    int mes;
    int ano;
} datas;

struct Ponto {
    double x;
    double y;
};

double calcularDistancia(struct Ponto p1, struct Ponto p2) {
    double difX = p1.x - p2.x;
    double difY = p1.y - p2.y;
    return sqrt(difX * difX + difY * difY);
}

int compararHoras(const struct Hora *a, const struct Hora *b) {
    if (a->hora != b->hora) {
        return a->hora - b->hora;
    }
    if (a->minuto != b->minuto) {
        return a->minuto - b->minuto;
    }
    return a->segundo - b->segundo;
}

int main(void) {
    int opcao;

    do {
        printf("\nEscolha uma opção:\n");
        printf("1. Questão 1 - Comparação de Horas\n");
        printf("2. Questão 2 - Cálculo da Quantidade de Dias\n");
        printf("3. Questão 3 - Cálculo da Distância entre Pontos\n");
        printf("0. Sair\n");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1: {
                // Questão 1 - Comparação de Horas
                struct Hora hora[5];
                int i;
                struct Hora maior_hora = {0, 0, 0};

                hora[0] = (struct Hora){2, 36, 59};
                hora[1] = (struct Hora){1, 15, 42};
                hora[2] = (struct Hora){15, 8, 17};
                hora[3] = (struct Hora){16, 23, 7};
                hora[4] = (struct Hora){2, 52, 21};

                for (i = 0; i < 5; i++) {
                    if (compararHoras(&hora[i], &maior_hora) > 0) {
                        maior_hora = hora[i];
                    }
                }

                printf("Maior hora Final: %02d:%02d:%02d\n", maior_hora.hora, maior_hora.minuto, maior_hora.segundo);
                break;
            }
            case 2: {
                // Questão 2 - Cálculo da Quantidade de Dias
                datas data[2];
                int qtd_dias = 0;
                int i;
                int dias_por_mes[] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

                data[0].dia = 6;
                data[1].dia = 15;
                data[0].mes = 6;
                data[1].mes = 9;
                data[0].ano = 1998;
                data[1].ano = 1968;

                for (i = 0; i < 2; i++) {
                    qtd_dias += data[i].dia;
                    for (int j = 1; j < data[i].mes; j++) {
                        qtd_dias += dias_por_mes[j];
                    }
                    // Levar em conta os anos bissextos
                    for (int j = data[i].ano + 1; j < data[i].ano; j++) {
                        qtd_dias += 365;
                        if (j % 4 == 0 && (j % 100 != 0 || j % 400 == 0)) {
                            qtd_dias++;
                        }
                    }
                }

                printf("Total de dias: %d\n", qtd_dias);
                break;
            }
            case 3: {
                // Questão 3 - Cálculo da Distância entre Pontos
                struct Ponto ponto1, ponto2;

                // Leitura das coordenadas do primeiro ponto
                printf("Digite as coordenadas do primeiro ponto (X Y): ");
                scanf("%lf %lf", &ponto1.x, &ponto1.y);

                // Leitura das coordenadas do segundo ponto
                printf("Digite as coordenadas do segundo ponto (X Y): ");
                scanf("%lf %lf", &ponto2.x, &ponto2.y);

                // Cálculo da distância
                double distancia = calcularDistancia(ponto1, ponto2);

                printf("A distância entre os pontos é: %.2lf\n", distancia);
                break;
            }
            case 0:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
        }
    } while (opcao != 0);

    return 0;
}
