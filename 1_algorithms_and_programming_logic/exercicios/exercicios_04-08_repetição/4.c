// Elabore um algoritmo que efetue a média aritmética de todos os números pares que se encontramno conjunto dos números inteiros de 1 até 100

# include <stdio.h>

int main() {
	
	int n = 2, cont = 0;
	float valor;
	
	while (n <= 100) {
	    valor += n;
	    n += 2;
	    cont ++;
	}
	
	printf("%.2f", valor / cont);
	
	return 0;
}
