// Construa um algoritmo que funcione como uma calculadora simples. A calculadora deve realizar asoperações de soma (+), subtração (-), multiplicação (*) e divisão (/). O usuário deve informar aoalgoritmo dois operandos (dois números) e a operação. O algoritmo deve retornar o resultado daoperação ou uma mensagem de erro caso o usuário solicite uma operação não definida

#include <stdio.h>

int main() {
    
    float n1, n2;
    char opcao;
    
    printf("Valor 1: ");
    scanf("%f", &n1);
    
    printf("Valor 2: ");
    scanf("%f", &n2);
    
    printf("Qual operador?\nsoma (+)\nsubtração (-)\nmultiplicação (*)\ndivisão (/)\nDigitar símbolo: ");
    scanf(" %c", &opcao);
    
    switch (opcao) {
        case '+':
            printf("Resultado: %.2f", n1 + n2);
            break;
        case '-':
            printf("Resultado: %.2f", n1 - n2);
            break;
        case '*':
            printf("Resultado: %.2f", n1 * n2);
            break;
        case '/':
            printf("Resultado: %.2f", n1 / n2);
            break;
        default:
            printf("Número inválido.");
            break;
    }

    return 0;
}
