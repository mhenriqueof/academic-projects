# include <stdio.h>

int main() {
	
	int numero_filtros, tomadas, tomadas_total = 0;
	
	while (1) {
		
		printf("Numero de filtros [min 1 - max 10]: ");
		scanf("%d", &numero_filtros);
		
		if (numero_filtros > 0 && numero_filtros < 11) {
			break;
		}
		printf("Valor invalido.\n");		
	}
	
	for (int i = 1; i <= numero_filtros; i++) {
		
		while (1) {
			
			printf("Numero de tomadas do filtro %d [min 2 - max 10]: ", i);
			scanf("%d", &tomadas);
			
			if (tomadas >= 2 && tomadas <= 10) {
				break;
			}
			printf("Valor invalido.\n");
		}
		
		if (i != numero_filtros) {
			tomadas -= 1;
		}
		
		tomadas_total += tomadas;
		
	}
	printf("%d aparelhos", tomadas_total);
	
	return 0;
}

