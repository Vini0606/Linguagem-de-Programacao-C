#include <stdio.h>
#include <limits.h>

int main(void) {

	// Declarar Variáveis
	int questao;
	int num, i;
	int n;
	int quantidade, numero, maior, menor, contador;
	float s;
  
	while (questao) {

		  // Criar Menu de Opções
		  printf("\n__________________________________\n\n");
		  printf("Escolha uma Questão: \n\n");
		  printf("0 - Sair");
		  printf("\n1 - Questão 1");
		  printf("\n2 - Questão 2");
		  printf("\n3 - Questão 3");
		  printf("\n4 - Questão 4");
		  printf("\n\nDigite o número da questão desejada: ");
		  scanf("%d", &questao);

		switch (questao) { 
			
			case 1:
				
				printf("__________________________________\n\n");
				num = 1;
				maior = INT_MIN;
				menor = INT_MAX;
				while (num >= 0) {
					printf("Digite um valor: ");
					scanf("%d", &num);
					if (num > maior) {
						maior = num;
					}
					if (num < menor && num >= 0) {
						menor = num;
					}
				}
				printf("Maior: %d", maior);
				printf("\nMenor: %d", menor);
				break;
			
			case 2:    
				
				printf("__________________________________\n\n");
				num = 0;
				i = 0;
				printf("Digite um número positivo: ");
				scanf("%d", &num);
				printf("Os divisores de %d são: ", num);
				for (i = 1; i <= num; i++) {
					if (num % i == 0) {
						printf("%d ", i);
					}
				}
				break;
			
			case 3:
				
				printf("__________________________________\n\n");
				n = 0;
				s = 0;
				printf("Digite o valor de N: ");
				scanf("%d", &n);
				for (i = 1; i <= n; i++) {
						  s += (2 * i - 1) / (float) i; 
				}
				printf("A somatoria S é: %.2f", s);
				break;
			
			case 4:      
				
				printf("__________________________________\n\n");
				quantidade = 0;
				numero = 0; 
				maior = 0; 
				contador = 0;
				printf("Digite a quantidade de numeros a serem lidos: ");
				scanf("%d", &quantidade);
				printf("Digite um numero: ");
				scanf("%d", &numero);
				maior = numero;
				contador = 1;
				for (i = 1; i < quantidade; i++) {
					printf("Digite outro numero: ");
					scanf("%d", &numero);      
					if (numero > maior) {
						maior = numero;
						contador = 1;
					} else if (numero == maior) {
						contador++;
						}
					}
				printf("O maior numero lido foi %d, e ele foi lido %d vezes.\n", maior, contador);
				break;
		}
	} 
  
  return 0;
}