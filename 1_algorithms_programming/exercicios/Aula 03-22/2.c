// Efetuar a leitura de um valor numérico inteiro positivo ou negativorepresentado pela variável N e apresentar o valor lido como sendo positivo. Dica: se o valorlido for menor que zero, ele deve ser multiplicado por -1.

#include <stdio.h>

int main() {
    
    int n;
    
    printf("Digite o número inteiro diferente de zero: ");
    scanf("%d", &n);
    
    if (n == 0) {
        printf("Não pode ser 0.\n");
    } else {
        if (n < 0) {
            n = n * -1;
        }
        printf("%d", n);
    }

    return 0;
}
