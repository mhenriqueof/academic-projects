# include <stdio.h>
# include <stdlib.h>
# include <time.h>

int main() {

    int n, valor, soma = 0;
    srand(time(NULL));  

    printf("Digite o numero de posicoes do vetor: ");
    scanf("%d", &n);

    int vetor[n];
    
    printf("Informe o vetor: \n");

    for (int i = 0; i < n; i++) {
    	
        vetor[i] = rand() % 11;
        printf("%d ", vetor[i]);
    }
    
    valor = vetor[0];
    
    printf("\n");
    
    printf("Vetor gerado: \n");
    
    for (int i = 0; i < n; i++) {
    	
        if (vetor[i] % valor == 0) {
        	if (vetor[i] != 0) {
        		soma += vetor[i];
        		vetor[i] = -1;
			}	
		}
		printf("%d ", vetor[i]);
    }
    printf("\nSoma: %d", soma);

    return 0;
}

