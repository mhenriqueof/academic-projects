# include <stdio.h>

int main() {
		
	float saldo = 100.00, deposito, saque;
	int opcao; 
	
	printf("1 - Verificar saldo\n");
	printf("2 - Realizar saque\n");
	printf("3 - Efetuar deposito\n");
	scanf("%d", &opcao);
	
	switch(opcao) {
		
		case 1: 
			printf("O saldo e de %.2f", saldo);
			break;
		
		case 2: 
			printf("Qual e o valor do saque?: ");
			scanf("%f", &saque);
			
			if (saque <= saldo) {
				
				saldo= saldo - saque;
				printf("O saldo atual e : %.2f", saldo);
				
			}	else {
				printf("O saldo e insuficiente.");
		
			}
					
			break;
			
		case 3:
			printf("Qual e o valor para deposito?: ");
			scanf("%f", &deposito);
			
			saldo = saldo + deposito;
			printf("O saldo atual e : %.2f", saldo);
			break;
			
		default:
			printf("Opcao invalida.");
			
	}
	
	return 0;
		
}
