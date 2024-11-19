// Um vendedor de uma loja de sapatos recebe como pagamento 20% de comissãosobre as vendas do mês e R$5,00 por cada par de sapatos vendidos. Escreva umalgoritmo que, dado o valor total das vendas do mês e o número de sapatosvendidos, mostre qual será o salário do vendedor naquele mês.

#include <stdio.h>

int main() {
    
    const float COMISSAO = 0.20;
    const float VALOR_SAPATO = 5;
    
    float vendas, salario;
    int sapatos_vendidos;
    
    printf("Total de vendas: ");
    scanf("%f", &vendas);
    
    printf("Sapatos vendidos: ");
    scanf("%d", &sapatos_vendidos);
    
    salario = (vendas * COMISSAO) + (VALOR_SAPATO * sapatos_vendidos);
    
    printf("O salário é %.2f", salario);
    
}