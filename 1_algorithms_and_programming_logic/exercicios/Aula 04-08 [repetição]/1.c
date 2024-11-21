// Elaborar um programa que leia dez valores numéricos reais e apresente no final a soma e a médiados valores lidos.

#include <stdio.h>

int main() {
	
	int cont = 10;
	float valor, resultado;
	
	while (cont != 0) {
		printf("Valor do %dº numero: ", cont);
		scanf("%f", &valor);
		
		resultado += valor;
		cont -= 1;
	}
	
	printf("Média: %f", resultado / 10);
	
	return 0;
}
