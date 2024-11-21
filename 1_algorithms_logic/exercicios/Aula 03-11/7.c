// Escreva um algoritmo que pergunte ao usuário a quantidade de km percorridos porum carro alugado e a quantidade de dias pelos quais ele foi alugado. Calcule emostre o valor a pagar, sabendo que o carro custa R$70,00 por dia e R$0,15 por kmrodado.

#include <stdio.h>

int main() {
    
    float km_rodado, valor;
    int dias;
    
    printf("Km rodados: ");
    scanf("%f", &km_rodado);
    
    printf("Dias usados: ");
    scanf("%d", &dias);
    
    valor = (km_rodado * 0.15) + (dias * 70);
    
    printf("O valor a pagar é: %.2f", valor);
    
}
