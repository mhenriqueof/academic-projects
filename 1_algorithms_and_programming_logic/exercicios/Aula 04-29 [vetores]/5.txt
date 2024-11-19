#include <stdio.h>

int main() {
    
    int vetor[8], valor, flag = 0;
    
    for (int i = 0; i < 8; i++) {

        while (1) {

            printf("Valor %d [numero inteiro positivo]: ", i+1);
            scanf("%d", &valor);
            
            if (valor < 0) {
                continue;
            }
           
            if (valor - (int)valor == 0) {
                break;
            }

            printf("Valor invalido.\n");
            }

        vetor[i] = valor;
    }
    
    printf("Valor a ser analisado: ");
    scanf("%d", &valor);
    
    // printf("%d", valor);
    
    for (int i = 0; i < 8; i++) {
        if (valor == vetor[i]) {
            flag = 1;
            break;
        }
    }
    
    if (flag == 1) {
        printf("Está contido.");
    } else {
        printf("Não está contido.");
    }

    return 0;
}