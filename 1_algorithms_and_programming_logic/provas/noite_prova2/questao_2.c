# include <stdio.h>

int main() {
	
	int x, y, maior, menor, soma = 0;
	
	printf("Valor de X: ");
	scanf("%d", &x);
	
	printf("Valor de Y: ");
	scanf("%d", &y);
	
	if (x > y) {
		maior = x;
		menor = y;
	} else {
		maior = y;
		menor = x;
	}
	
	for (int i = menor+1; i < maior; i++) {
		
		if (i % 2 == 1 || i % 2 == -1) {
			soma += i;
			
		}
		
	}
	printf("%d", soma);
	
	return 0;	
}

