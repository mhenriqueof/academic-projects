// Faça um programa que efetue o cálculo do salário bruto de um professor.Os dados fornecidos serão: valor da hora aula, número de aulas dadas no mês e percentualde desconto do INSS.

#include <stdio.h>

int main() {
    
    float salario_liquido, valor_hora, desconto_inss;
    int aulas_dadas;
    
    printf("Valor hora aula: ");
    scanf("%f", &valor_hora);
    
    printf("Número de aulas dadas: ");
    scanf("%d", &aulas_dadas);
    
    printf("Taxa do INSS: ");
    scanf("%f", &desconto_inss);
    
    printf("Salário líquido: %.2f", ((valor_hora * aulas_dadas) * (1 - (desconto_inss / 100))));
    
    return 0;
}
