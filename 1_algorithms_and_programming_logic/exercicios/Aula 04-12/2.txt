// Escrever um algoritmo que leia uma quantidade desconhecida de números e conte quantos delesestão nos seguintes intervalos: [0,25], [26,50], [51,75] e [76,100]. A entrada de dados deve terminarquando for lido um número negativo

#include <stdio.h>

int main() {
    
    int i1 = 0, i2 = 0, i3 = 0, i4 = 0;
    float n;
    
    do {
        
        printf("Número: ");
        scanf("%f", &n);
        
        if (n > 75) {
            printf("O número %.2f está no intervalo [76,100].\n", n);
            i4++;
        } else if (n > 50) {
            printf("O número %.2f está no intervalo [51,75].\n", n);
            i3++;
        } else if (n > 25) {
            printf("O número %.2f está no intervalo [26,50].\n", n);
            i2++;
        } else {
            printf("O número %.2f está no intervalo [0,25].\n", n);
            i1++;
        }

    } while (n >= 0 && n <= 100);
    
    printf("[0,25] = %d\n[26,50] = %d\n[51,75] = %d\n[76,100] = %d\n", i1, i2, i3, i4);

    return 0;
}