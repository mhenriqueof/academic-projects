// Todo restaurante, embora por lei não possa obrigar o cliente a pagar, cobra 10% decomissão para o garçom. Escreva um algoritmo que leia o valor gasto pelo clienteem um restaurante e mostre o valor da gorjeta e o valor total a ser pago.

#include <stdio.h>

int main() {
    
    const float COMISSAO = 0.10;
    
    float valor, gorjeta, total;
    
    printf("Valor gasto: ");
    scanf("%f", &valor);
    
    gorjeta = valor * COMISSAO;
    total = valor + gorjeta;
    
    printf("A gorjeta é de %.2f e o total a pagar é %.2f", gorjeta, total);
}
