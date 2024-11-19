// Escreva um algoritmo que leia um valor inicial A e uma razão R e imprima uma sequência emprogressão geométrica contendo 10 valores.○ Por exemplo, com A = 1 e R = 3, tem-se “1.00 3.00 9.00 27.00 81.00 243.00 729.00 2187.006561.00 19683.00”

#include <stdio.h>
# include <math.h>

int main() {
    
    float a1, razao, r;
    
    printf("a1: ");
    scanf("%f", &a1);
    
    printf("Razao: ");
    scanf("%f", &razao);
    
    for (int i = 1; i <= 10; i++) {
        printf("%.2f | ", a1 * pow(razao, i-1));
    }
    
    return 0;
}
