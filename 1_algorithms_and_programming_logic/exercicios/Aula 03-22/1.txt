// Elabore um algoritmo que leia dois números e imprima qual é maior, qual émenor, ou se são iguais.

#include <stdio.h>

int main() {
    
    float a, b;
    
    printf("Valor de A: ");
    scanf("%f", &a);
    
    printf("Valor de B: ");
    scanf("%f", &b);
    
    if (a == b) {
        printf("O números são iguais.");
    } else if (a > b) {
        printf("Maior A: %f\nMenor B: %f", a, b);
    } else {
        printf("Maior B: %f\nMenor A: %f", b, a);
    }

    return 0;
}
