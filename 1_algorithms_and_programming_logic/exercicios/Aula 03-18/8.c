// Você está endividado e quer administrar melhor sua vida financeira. Paraisso, faça um programa que recebe o valor de uma dívida e o juro mensal, então calcule eimprima o valor da dívida no mês seguinte.

#include <stdio.h>

int main() {
    
    float valor_divida, juro_mensal, taxa;
    
    printf("Valor da dívida: ");
    scanf("%f", &valor_divida);
    
    printf("Juros mensal: ");
    scanf("%f", &juro_mensal);
    
    taxa = juro_mensal / 100;
    
    printf("Valor da dívida: %.2f", (valor_divida * (1 + (taxa))));

    return 0;
}
