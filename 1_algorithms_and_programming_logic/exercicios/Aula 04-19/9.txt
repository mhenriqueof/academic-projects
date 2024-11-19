// Escreva um algoritmo para solicitar o valor de N (inteiro) e gerar H(real) conforme a fórmula a seguir

#include <stdio.h>

int main() {
    
    int numero;
    float soma = 0;
    
    printf("Numero inteiro: ");
    scanf("%d", &numero);
    
    for (int i = 1; i <= numero; i++) {
        soma = soma + (1/(float)i);
    }
    printf("%.2f", soma);
    
    return 0;
}
