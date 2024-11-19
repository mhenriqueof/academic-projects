# include <stdio.h>

int main() {
	
	int a = 300, b = 1500, c = 600, d = 1000, e = 150;
	int gramas, porcao, total = 0;
	
	for (int i = 1; i <= 5; i++) {
		
		if (i == 1) {
			gramas = a;
		} else if (i == 2){
			gramas = b;
		} else if (i == 3){
			gramas = c;
		} else if (i == 4) {
			gramas = d;
		} else {
			gramas = e;
		}
		
		while (1) {
			
			printf("Porcao do %d convidado [min 1 - 10 max]: ", i);
			scanf("%d", &porcao);
			
			if (porcao >= 1 && porcao <= 10) {
				break;
			}
			
			printf("Valor invalido.\n");
		}
		
		total += porcao * gramas;
		
	}
	printf("%d", total + 225);
	
	return 0;
}

