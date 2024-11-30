// Em uma loja de eletrodomésticos, as compras têm um preço à vista, ou acréscimo de 10 % parapagamentos em 2 vezes, ou ainda, acréscimo de 20% para pagamento em 3 vezes. O algoritmodeve pedir para o usuário digitar o valor da compra à vista e a opção de compra. O algoritmo deveexibir qual o valor final a ser pago

#include <stdio.h>

int main() {
    
    float valor, juros;
    int opcao;
    
    printf("Valor da compra: ");
    scanf("%f", &valor);
    
    printf("Opção de pagamento:\n[1] à vista sem juros\n[2] 2x com juros de 10%\n[3] 3x com juros de 20%\n");
    scanf("%d", &opcao);
    
    switch (opcao) {
        case 1:
            juros = 0;
            break;
        case 2:
            juros = 0.10;
            break;
        case 3:
            juros = 0.20;
            break;
    }
    printf("Valor: %.2f", valor * (1+ juros));

    return 0;
}
