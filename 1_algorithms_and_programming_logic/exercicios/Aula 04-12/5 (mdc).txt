// Escreva um programa que leia dois números inteiros e calcule o máximo divisor comum (MDC)desses números

#include <stdio.h>

int main() {
    
    int n = 1, n1, n2, r1, r2, mdc;
    
    printf("Numero 1: ");
    scanf("%d", &n1);
    
    printf("Numero 2: ");
    scanf("%d", &n2);
    
    while (n < (n1 + n2)) {
        
        r1 = n1 % n;
        r2 = n2 % n;
        
        if (r1 == 0 && r2 == 0) {
            mdc = n;
        }

        n++;
    }
    
    printf("MDC: %d", mdc);
    
    return 0;
}
