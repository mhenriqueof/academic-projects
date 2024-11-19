// Crie um algoritmo para calcular a taxa de serviço do garçom, a partir daentrada do valor da conta. A taxa de serviço é fixa em 10%. O sistema deverá escrever natela o valor da taxa de serviço e depois o valor total a ser pago.

#include <stdio.h>

# define TAXA 10.00

int main() {
    
    float valor, valor_taxa;
    
    printf("Valor da conta: ");
    scanf("%f", &valor);
    
    valor_taxa = valor * (TAXA / 100);
    
    printf("Valor da taxa de serviço: %.2f \nValor total: %.2f", valor_taxa, (valor + valor_taxa));
    
    return 0;
}
