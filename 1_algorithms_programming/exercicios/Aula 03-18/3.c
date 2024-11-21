// Calcular o aumento que será dado a um funcionário, obtendo do usuário asseguintes informações: salário atual e a porcentagem de aumento. Apresentar o novo valordo salário e o valor do aumento.

#include <stdio.h>

int main() {
    
    float salario_atual, taxa;
    
    printf("Salário atual: ");
    scanf("%f", &salario_atual);
    
    printf("Porcentagem de aumento: ");
    scanf("%f", &taxa);
    
    taxa = (taxa / 100);
    
    printf("O novo salário é %.2f e o aumento foi de %.2f", (salario_atual * (1 + taxa)), salario_atual * taxa);
    
    return 0;
}
