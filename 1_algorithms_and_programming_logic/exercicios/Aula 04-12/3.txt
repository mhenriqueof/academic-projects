// Escreva um programa que leia uma sequência de números inteiros positivos e negativos, e imprimaa soma dos números positivos e a soma dos números negativos

#include <stdio.h>

int main() {
    
    float n, positivo, negativo;
    
    do {
        printf("Digite o número: ");
        scanf("%f", &n);
        
        if (n > 0) {
            positivo += n;
        } else {
            negativo += n;
        }
    } while (n != 0);
    
    printf("Negativo: %.2f\nPositivo: %.2f", negativo, positivo);

    return 0;
}
