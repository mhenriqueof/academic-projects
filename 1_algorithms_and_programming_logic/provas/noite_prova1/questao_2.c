# include <stdio.h>

int main() {
	
	float quilos_maca, quilos_morango, valor_kg_maca, valor_kg_morango, peso_total, valor_total;
	
	printf("Quilos maca: ");
	scanf("%f", &quilos_maca);
	
	printf("Quilos morango: ");
	scanf("%f", &quilos_morango);
	
	peso_total = quilos_maca + quilos_morango;
	
		
	if (quilos_maca > 5) {
		valor_kg_maca = 6.5;
	} else {
		valor_kg_maca = 7.99;
    }
    
	if (quilos_morango > 5) {
		valor_kg_morango = 10.75;
	} else {
		valor_kg_morango = 13.5;
	}
	
	valor_total = (quilos_maca * valor_kg_maca) + (quilos_morango * valor_kg_morango);
	
	
	if (peso_total > 10 || valor_total > 50) {
		valor_total = valor_total * 0.9;
	}

	printf("Valor total: %.2f", valor_total);	
	
	return 0;
}

