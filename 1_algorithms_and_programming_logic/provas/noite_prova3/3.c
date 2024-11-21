#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    float matriz[12][12], soma = 0;
    srand(time(NULL));
	
	char opcao;
	
	printf("Digite S para Soma ou M para Media: ");
	scanf("%c", &opcao);
	
	for (int i = 0; i < 12; i++) {
		
		for (int j = 0; j < 12; j++) {
			matriz[i][j] = rand() % 101;
			printf("%.1f ", matriz[i][j]);
		}
		printf("\n");
	}   	   
	
	for (int i = 0; i < 12; i++) {
		
		for (int j = 0; j < 12; j++) {
			
			if (j < i) {
				soma += matriz[i][j];
				printf("%.1f ", matriz[i][j]);
			}	
		}
		printf("\n");
	} 
	
	printf("\n");
	
	if (opcao == 's' || opcao == 'S') {
		printf("Soma: %.1f", soma);
	} else if (opcao == 'm' || opcao == 'M') {
		printf("Media: %.1f", soma / 66);
	} else {
		printf("Letra invalida.");
	}

    return 0;
}

