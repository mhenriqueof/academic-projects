// (Beecrowd | 1038) Com base na tabela abaixo, escreva umprograma que leia o código de um item e a quantidade deste item. A seguir,calcule e mostre o valor da conta a pagar.

#include <stdio.h>

int main() {
    
    int codigo, quantidade;
    float valor;
    
    printf("\
[1] Cachorro-quente | R$ 12,00\n\
[2] X-Salada | R$ 15,50\n\
[3] X-Bacon | R$ 18,00\n\
[4] Torrada simples | R$ 8,00\n\
[5] Refrigerante | R$ 4,50\n");

    printf("Código: ");
    scanf("%d", &codigo);
    
    switch (codigo) {
        case 1:
            valor = 12;
            break;
        
        case 2:
            valor = 15.5;
            break;
        
        case 3:
            valor = 18;
            break;
        
        case 4:
            valor = 8;
            break;
        
        case 5:
            valor = 4.5;
            break;
            
        default:
            printf("Valor inválido.");
            return 1;
    }
        
    printf("Quantidade: ");
    scanf("%d", &quantidade);
    
    printf("Valor a pagar: %.2f", valor * quantidade);
    
    return 0;
}
