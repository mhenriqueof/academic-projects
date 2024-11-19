// Faça um programa que leia um número inteiro e imprima se é par ou ímpar, usando o comandoswitch

#include <stdio.h>

int main() {
    
    int n, valor;
    
    printf("Número: ");
    scanf("%d", &n);
    
    valor = n % 2;
    
    switch (valor) {
        
        case 0:
            printf("O número é par.");
            break;
        case 1:
            printf("O número é ímpar.");
            break;
    }

    return 0;
}
