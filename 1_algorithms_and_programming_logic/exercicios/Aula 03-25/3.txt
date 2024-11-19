// Escreva um programa que receba um número inteiro de 1 a 7 e exiba o dia da semanacorrespondente

#include <stdio.h>

int main() {
    
    int n;
    
    printf("Número dia da semana: ");
    scanf("%d", &n);
    
    switch (n) {
        case 1:
            printf("Domingo");
            break;
        case 2:
            printf("Segunda");
            break;
        case 3:
            printf("Terça");
            break;
        case 4:
            printf("Quarta");
            break;
        case 5:
            printf("Quinta");
            break;
        case 6:
            printf("Sexta");
            break;
        case 7:
            printf("Sábado");
            break;
        default:
            printf("Número inválido.");
            break;

    return 0;
    }
}
