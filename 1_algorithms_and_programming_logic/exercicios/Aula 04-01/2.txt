// Escreva um programa que leia dois números inteiros A e B doteclado e imprima as mensagens “nulo”, “sinal negativo” ou “sinal positivo”,conforme o resultado da multiplicação de A por B

#include <stdio.h>

int main() {
    
    int a, b, valor;
    
    printf("A: ");
    scanf("%d", &a);
    
    printf("B: ");
    scanf("%d", &b);
    
    valor = a * b;
    
    if (valor == 0) {
        printf("Nulo.");
    } else if (valor > 0) {
        printf("Sinal positivo.");
    } else {
        printf("Sinal negativo.");
    }

    return 0;
}
