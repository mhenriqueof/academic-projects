// Antes de o racionamento de energia ser decretado, quase ninguém falava emquilowatts; mas, agora, todos incorporaram essa palavra em seu vocabulário. Sabendo-seque 100 quilowatts de energia custa um sétimo do salário mínimo, faça um programa quereceba o valor do salário mínimo e a quantidade de quilowatts gasta por uma residência eimprima:
// ● o valor em reais de cada quilowatt;
// ● o valor em reais a ser pago

#include <stdio.h>

int main() {
    
    float valor_quilowatts, quilowatts, salario_min;

    printf("Salário mínimo: ");
    scanf("%f", &salario_min);
    
    valor_quilowatts = (salario_min / 7) / 100;
    
    printf("Quantidade quilowatts usado: ");
    scanf("%f", &quilowatts);
    
    printf("Valor de cada quilowatts: %.2f\nValor a pagar: %.2f", valor_quilowatts, (valor_quilowatts * quilowatts));
    
    return 0;
}
