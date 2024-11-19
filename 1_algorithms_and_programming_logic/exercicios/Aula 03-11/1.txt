// Crie um algoritmo que leia o valor da variável do tipo real x digitado pelo usuário eescreva na tela o valor de x².

#include <stdio.h>

int main() {
    
    float n;
    printf("Digite o número: ");
    scanf("%f", &n);
    
    printf("%.2f", n*n);
    
}
