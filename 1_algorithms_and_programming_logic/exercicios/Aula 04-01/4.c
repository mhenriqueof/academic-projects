// Em uma certa papelaria, até 100 folhas, a cópia do xerox custaR$ 0,25 e, acima de 100 folhas, cada cópia adicional custa R$ 0,20. Escrevaum algoritmo que dado o número total de cópias, informe o valor a ser pago

#include <stdio.h>

int main() {
    
    float qtd, qtd_mais;
    
    printf("Quantidade folhas: ");
    scanf("%f", &qtd);
    
    qtd_mais = qtd - 100;
    
    if (qtd_mais < 0) {
        qtd_mais = 0;
    } else {
        qtd = 100;
    }
    
    printf("Valor a pagar: %.2f", (0.25 * qtd) + (0.20 * qtd_mais));

    return 0;
}
