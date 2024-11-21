// Escreva um algoritmo que leia um valor inicial A e uma razão R e imprima uma sequência emprogressão aritmética contendo 10 valores.○ Por exemplo, com A = 1 e R = 3, tem-se “1 4 7 10 13 16 19 22 25 28”

#include <stdio.h>

int main() {
    
    float a1, razao;
    
    printf("a1: ");
    scanf("%f", &a1);
    
    printf("Razao: ");
    scanf("%f", &razao);
    
    for (int i = 1; i <= 10; i++) {
        printf("%.2f | ", a1 + (i - 1) * razao);
    }
    
    return 0;
}
