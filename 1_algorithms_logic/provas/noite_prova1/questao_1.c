# include <stdio.h>

int main() {
	
	int combustivel;
	float litros, desconto, preco_litro, valor_total;
	
	printf("Quantidade de litros abastecidos: ");
	scanf("%f", &litros);
	
	printf("[1] Etanol\n[2] Gasolina\n");
	scanf("%d", &combustivel);
	
	switch (combustivel) {
		case 1:
			if (litros > 20) {
				desconto = 5;
			} else {
				desconto = 3;
			}
			printf("Preco do litro do etanol: ");
			scanf("%f", &preco_litro);
			break;
			
		case 2:
			if (litros > 20) {
				desconto = 6;
			} else {
				desconto = 3.5;
			}
			printf("Preco do litro da gasolina: ");
			scanf("%f", &preco_litro);
			break;
			
	}	
	
	valor_total = preco_litro * (1 - ((desconto / 100))) * litros;
	printf("%.2f\n", valor_total);
	
	printf("Valor a ser pago: %.2f", valor_total);
	
	return 0;
}

