#include <stdio.h>

int main() {
    
    int vetor[6], valor, soma, maior = 0, menor = 0;
    
    for (int i = 0; i < 6; i++) {
        while (1) {
            printf("Valor do indice %d: ", i);
            scanf("%d", &valor);
            
            if (valor % 2 == 0 && valor >= 1 && valor <= 20) {
                vetor[i] = valor;
                break;
            }
        }
    }
    
    maior = vetor[0];
    menor = vetor[0];
    
    printf("Valores salvos: ");
    for (int j = 0; j < 6; j++) {
        printf("%d ", vetor[j]);
        
        soma += vetor[j];
        
        if (vetor[j] > maior) {
            maior = vetor[j];
        }
        if (vetor[j] < menor) {
            menor = vetor[j];
        }
    }
    
    printf("\nMedia: %.2f | Maior: %d | Menor: %d", soma / 6.0, maior, menor);

    return 0;
}
