// Elaborar um programa que apresente todos os valores numéricos inteiros ímpares situados nointervalo de 0 a 20.

#include <stdio.h>

int main() {
    
    int n = 0;
    
    do {
        if (n % 2 == 1) {
            printf("%d\n", n);
        }
        n++;
    } while (n <= 20);


    return 0;
}
