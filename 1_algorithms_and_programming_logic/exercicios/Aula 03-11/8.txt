// Faça um programa que leia o nome de um vendedor, o seu salário fixo e o total devendas efetuadas por ele no mês (em dinheiro). Sabendo que este vendedor ganha15% de comissão sobre suas vendas efetuadas, informar o total a receber no finaldo mês.

#include <stdio.h>

int main() {
    
    char nome[50];
    float vendas, salario_fixo, salario;
    
    printf("Nome do funcionário: ");
    scanf("%s", nome);
    
    printf("Salário fixo: ");
    scanf("%f", &salario_fixo);
    
    printf("Vendas efetuadas em R$: ");
    scanf("%f", &vendas);
    
    salario = salario_fixo + (vendas * 0.15);
    
    printf("O salário de %s é %f", nome, salario);
    
}
