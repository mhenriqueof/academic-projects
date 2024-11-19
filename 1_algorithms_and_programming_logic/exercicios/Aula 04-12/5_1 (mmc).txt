// Escreva um programa que leia dois números inteiros e calcule o máximo divisor comum (MDC)desses números

#include <stdio.h>

int main() {
    
    int n = 1, n1, n2, r1, r2, mmc;
    
    printf("Numero 1: ");
    scanf("%d", &n1);
    
    printf("Numero 2: ");
    scanf("%d", &n2);
    
    while (1) {
        
        r1 = n % n1;
        r2 = n % n2;
        
        if (r1 == 0 && r2 == 0) {
            mmc = n;
            break;
        }

        n++;
    }
    
    printf("MMC: %d", mmc);
    
    return 0;
}
