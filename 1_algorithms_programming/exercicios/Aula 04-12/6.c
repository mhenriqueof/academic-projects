// Escreva um programa que leia uma sequência de números inteiros positivos e imprima o menor e omaior número lido

#include <stdio.h>

int main() {
    
    int num = 1, maior, menor, cont = 0;
    
    while (num > 0) {
        
        printf("Numero: ");
        scanf("%d", &num);
        
        if (cont == 0) {
            maior = num;
            menor = num;
        }
        
        if (num > maior) {
            maior = num;
        } else if (num < menor && num > 0) {
            menor = num;
        }
        
        cont++;
    }
    
    printf("Menor: %d | Maior: %d", menor, maior);

    return 0;
}
