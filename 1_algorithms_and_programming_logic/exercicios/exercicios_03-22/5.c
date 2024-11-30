// Desenvolva um algoritmo para aplicar um percentual de desconto sobre o valorde uma compra informado pelo usuário. Os percentuais de desconto são

#include <stdio.h>

int main() {
    
    float valor, desconto;
    
    printf("Valor da compra: ");
    scanf("%f", &valor);
    
    if (valor <= 0) {
        printf("Valor inválido.");
    } else {
        if (valor >= 500) {
            desconto = 0.15;
        } else if (valor >= 200) {
            desconto = 0.10;
        } else {
            desconto = 0.05;
        }
        printf("Valor sem desconto: %.2f\nValor do desconto: %.2f\nValor a ser pago: %.2f", valor, valor * desconto, valor * (desconto + 1));
    }
    
    return 0;
}
