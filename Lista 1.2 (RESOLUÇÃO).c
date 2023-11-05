#include <stdio.h>

int main(void) {

// Declarar Variáveis 

	int questao = -1;
	int num;
	int num1;
	int num2;
	float altura, peso_ideal;
	char sexo;
	int mes;
	int opcao;
	float valor1, valor2, resultado;

	// Criar Menu de Opções
	while (questao) {
	  
		printf("\n__________________________________\n\n");
		printf("Escolha uma Questão: \n\n");
		printf("0 - Sair");
		printf("\n1 - Questão 1");
		printf("\n2 - Questão 2");
		printf("\n3 - Questão 3");
		printf("\n4 - Questão 4");
		printf("\n5 - Questão 5");
		printf("\n6 - Questão 6");
		printf("\n7 - Questão 7");
		printf("\n\nDigite o número da questão desejada: ");
		scanf("%d", &questao);
		  
		// Executar Questão Escolhida
		switch (questao) {
		  case 1:
			printf("__________________________________\n\n");
			num1 = 0;
			num2 = 0;
			printf("Digite o primeiro número: ");
			scanf("%d", &num1);
			printf("Digite o segundo número: ");
			scanf("%d", &num2);
			if (num1 > num2) {
				printf("O primeiro número é o maior");    
			}
			else if (num2 > num1) {
				printf("O segundo número é o maior");
			}
			else {
				printf("Os números são iguais");
			}
			break;    
		  case 2: 
			printf("__________________________________\n\n");
			num1 = 0;
			num2 = 0;
			printf("Digite o numero 1, e o 2 logo em seguida: ");
			scanf("%d  %d", &num1, &num2);
			printf("%s", num1 > num2 ? "O primeiro é o maior" : num2 > num1 ? "O segundo é o maior" : "Os números são iguais");  
			break;
		  case 3:
			printf("__________________________________\n\n");
			num = 0;
			printf("Digite um número inteiro: ");
			scanf("%d", &num);
			if (num % 2 == 0) {
				printf("%d é um número par", num);    
			} else {
				printf("%d é um número ímpar", num);
			}
			break;
		  case 4:
			printf("__________________________________\n\n");
			altura = 0; 
			peso_ideal = 0;
			printf("Digite a altura da pessoa: ");
			scanf("%f", &altura);
			printf("Digite o sexo da pessoa (M/F): ");
			getchar();
			scanf("%c", &sexo);
			if (sexo == 'M' || sexo == 'm') {
				peso_ideal = (72.7 * altura) - 58;
				printf("O peso ideal para um homem de %.2f m de altura é: %.2f kg", altura, peso_ideal);
			} else if (sexo == 'F' || sexo == 'f') {
				peso_ideal = (62.1 * altura) - 44.7;
				printf("O peso ideal para uma mulher de %.2f m de altura é: %.2f kg", altura, peso_ideal);
			} else {
				printf("Sexo inválido!");
			}
			break;
		  case 5:
			printf("__________________________________\n\n");
			mes = 0;
			printf("Digite o numero do mes (1-12): ");
			scanf("%d", &mes);
			switch (mes) {
				case 1:
					printf("Janeiro\n");
					break;
				case 2:
					printf("Fevereiro\n");
					break;
				case 3:
					printf("Marco\n");
					break;
				case 4:
					printf("Abril\n");
					break;
				case 5:
					printf("Maio\n");
					break;
				case 6:
					printf("Junho\n");
					break;
				case 7:
					printf("Julho\n");
					break;
				case 8:
					printf("Agosto\n");
					break;
				case 9:
					printf("Setembro\n");
					break;
				case 10:
					printf("Outubro\n");
					break;
				case 11:
					printf("Novembro\n");
					break;
				case 12:
					printf("Dezembro\n");
					break;
				default:
					printf("Numero do mês invalido!\n");
					break;
			 }
		  break;
		  case 6:
			printf("__________________________________\n\n");
			opcao = 0;
			valor1 = 0;
			valor2 = 0; 
			resultado = 0;
		  
			printf("Escolha uma opção:\n\n");
			printf("1 - Adição\n");
			printf("2 - Subtração\n");
			printf("3 - Multiplicação\n");
			printf("4 - Divisão\n\n");
			printf("Opção escolhida: ");
			scanf("%d", &opcao);
		  
			switch (opcao) {
			  case 1:
				printf("Digite os valores a serem somados: ");
				scanf("%f %f", &valor1, &valor2);
				resultado = valor1 + valor2;
				printf("Resultado da adição: %.2f\n", resultado);
				break;
			  case 2:
				printf("Digite os valores a serem subtraídos (valor1 - valor2): ");
				scanf("%f %f", &valor1, &valor2);
				resultado = valor1 - valor2;
				printf("Resultado da subtração: %.2f\n", resultado);
				break;
			  case 3:
				printf("Digite os valores a serem multiplicados: ");
				scanf("%f %f", &valor1, &valor2);
				resultado = valor1 * valor2;
				printf("Resultado da multiplicação: %.2f\n", resultado);
				break;
			  case 4:
				printf("Digite os valores a serem dividios (valor1 / valor2): ");
				scanf("%f %f", &valor1, &valor2);
				if (valor2 == 0) {
				  printf("Erro: divisão por zero.\n");
				} else {
				  resultado = valor1 / valor2;
				  printf("Resultado da divisão: %.2f\n", resultado);
				}
				break;
			  default:
				printf("Opção inválida.\n");
				break;
			}
		  
		 break;
		 case 7:
		   printf("__________________________________\n\n");
		   num = 0;
		   printf("Digite um número inteiro: ");
		   scanf("%d", &num);
		   if (num % 3 == 0 && num % 5 == 0) {
			printf("O número é divisível por 3 e 5 simultaneamente.");
		   }
		   else if (num % 3 == 0) {
			printf("O número é divisível por 3.");
		   }
		   else if (num % 5 == 0) {
			printf("O número é divisível por 5.");
		   }
		   else {
			printf("O número não é divisível por 3 nem por 5.");
		  }
		}

	}
  
  return 0;
}

