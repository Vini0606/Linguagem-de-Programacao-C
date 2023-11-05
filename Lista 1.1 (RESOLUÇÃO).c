#include <stdio.h>

int main(void) {  

	// Declarar Variáveis e Vetores

	int questao = -1;
	int valor_inteiro = 0;
	float valor_real = 0;
	int dia;
	char mes[20];
	int ano;
	int hora;
	int minutos;
	char caracteres[3];
	float valor1 = 0;
	float valor2 = 0;


	while (questao) {
	  
		// Criar Menu de Opções
		printf("__________________________________\n\n");
		printf("Escolha uma Questão: \n\n");
		printf("0 - Sair");
		printf("\n1 - Questão 1");
		printf("\n2 - Questão 2");
		printf("\n3 - Questão 3");
		printf("\n4 - Questão 4");
		printf("\n5 - Questão 5");
		printf("\n\nDigite o número da questão desejada: ");
		scanf("%d", &questao);
		  
		switch (questao) {

		  // Questão 1
		  case 1:
			printf("\nDigite um numero inteiro: ");
			scanf("%d", &valor_inteiro);  
			printf("Valor lido: %d\n", valor_inteiro);
		  break;

		  // Questão 2
		  case 2:
			printf("\nDigite o Valor Float: ");
			scanf("%f", &valor_real);  
			printf("Valor lido: %.1f\n", valor_real);
		  break; 
			
		  // Questão 3
		  case 3:
			printf("\nDigite o dia do mês: ");
			scanf("%d", &dia);  
			printf("Digite o nome do mês: "); 
			scanf("\n%s", mes);
			printf("Digite o ano: ");
			scanf("%d", &ano);
			printf("Digite a hora: ");
			scanf("%d", &hora);
			printf("Digite os minutos: ");
			scanf("%d", &minutos);
			printf("\nData: %d/%s/%d\n", dia, mes, ano);
			printf("Hora: %d:%d\n", hora, minutos);
		  break;

		  // Questão 4
		  case 4:
			printf("\nDigite os 3 caracteres desejados: ");
			getchar();
			caracteres[0] = getchar();
			getchar();
			caracteres[1] = getchar();
			getchar();
			caracteres[2] = getchar();
			printf("\n%c\n%c\n%c\n", caracteres[0],caracteres[1],caracteres[2]);
		  break;

		  // Questão 5
		  case 5:
			printf("\nDigite dois valores tipo float com até DUAS casas decimais: ");
			scanf("%f%f", &valor1, &valor2);
			printf("\nvalor 2: %.2f\nvalor 1: %.2f\n", valor2, valor1);
		}  
	  
	}  
  
  return 0;
}

