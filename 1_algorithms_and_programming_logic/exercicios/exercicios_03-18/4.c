// Escreva um algoritmo que leia o valor total devido por um cliente, quantidadede dias de atraso e percentual de multa por dia de atraso. Aplique a porcentagem de multapelo atraso do pagamento e imprima o valor total devido.

#include <stdio.h>

int main() {
    
    float valor, porc_multa;
    int dias;
    
    printf("Valor total: ");
    scanf("%f", &valor);
    
    printf("Quantidade de dias de atraso: ");
    scanf("%d", &dias);
    
    printf("Porcentagem de multa por dia de atraso: ");
    scanf("%f", &porc_multa);
    
    porc_multa = porc_multa / 100;
    
    printf("Valor a ser pago é %.2f", (valor * ((dias * porc_multa) + 1)));
    
    return 0;
}
