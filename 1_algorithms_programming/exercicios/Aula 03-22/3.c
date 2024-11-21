// Uma empresa qualquer decidiu conceder um aumento de salários a seusfuncionários de acordo com a tabela a seguir:

#include <stdio.h>

int main() {
    
    float salario, aumento;
    
    printf("Salário atual: ");
    scanf("%f", &salario);

    if (salario > 5000) {
        printf("Sem aumento. Seu salário continua %.2f", salario);
    } else if (salario <= 0) {
        printf("Valor inválido.");
    } else {
        if (salario > 3800) {
        aumento = 4;
    } else if (salario > 3000) {
        aumento = 7;
    } else if (salario > 2000) {
        aumento = 10;
    } else if (salario > 1400) {
        aumento = 12;
    } else {
        aumento = 15;
    }
    printf("Seu aumento é de %.0f%%. Seu novo salário é %.2f.", aumento, salario * (aumento / 100 + 1));
    }
    
    return 0;
}
