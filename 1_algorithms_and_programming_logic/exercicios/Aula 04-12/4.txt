// Escreva um programa que leia números inteiros positivos até que o número 0 seja digitado eimprima a média desses números

#include <stdio.h>

int main() {
    
    int n = -1, resultado, num;
    
    do {
        printf("Número inteiro positivo: ");
        scanf("%d", &num);
        
        resultado += num;
        n++;
    } while (num > 0);
    
    printf("%d", resultado / n);
    
    return 0;
}
