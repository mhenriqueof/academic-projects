// Elaborar um programa que leia um número inteiro positivo do teclado e mostre a sua tabuada de 1a 10

# include <stdio.h>

int main() {
	
	int n, cont = 1;
	
	printf("Taduada do: ");
	scanf("%d", &n);
	
	while (cont != 11) {
	    printf("%d x %d = %d\n", n, cont, n * cont);
	    cont ++;
	}
	
	return 0;
}
