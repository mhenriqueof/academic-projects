// Faça um programa que leia dois números reais, um será o valor de umproduto e outro o valor de desconto que esse produto está recebendo. Imprima quantosreais o produto custa na promoção.

#include <stdio.h>

int main() {
    
    float valor, desconto;
    
    printf("Valor do produto: ");
    scanf("%f", &valor);
    
    printf("Taxa de desconto: ");
    scanf("%f", &desconto);
    
    printf("O produto custa %.2f na promoção.", (valor - desconto));
    
    return 0;
}
