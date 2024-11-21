// Elaborar um programa que apresente o valor da conversão em dólar (US$) de umvalor lido em real (R$). O programa deve solicitar ao usuário o valor da cotação dodólar e também a quantidade de reais disponível.

#include <stdio.h>

int main() {
    
    const float DOLAR = 4.98;
    float reais;
    
    printf("Valor em reais: ");
    scanf("%f", &reais);
    
    printf("O valor de R$ %.2f em dólares é %.2f", reais, (reais / DOLAR));
    
}
