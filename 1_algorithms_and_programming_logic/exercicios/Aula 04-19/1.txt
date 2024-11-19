// Dado um valor n inteiro positivo lido do teclado, exibir n linhas em que cada linha contém tantosasteriscos (*) quanto for o número da linha.○ Por exemplo, lendo o número 3, a linha 1 deve exibir “*”, a linha 2 deve exibir “**” e a linha 3deve exibir “***”) for lido, oalgoritmo deverá cessar sua execução

#include <stdio.h>

int main() {
    
    int numero, cont = 1;
    
    printf("Numero: ");
    scanf("%d", &numero);
    
    while (1) {
        
        for (int i = 1; i <= cont; i++) {
            printf("*");
        }
        printf("\n");

        if (cont == numero) {
            break;
        }
        cont++;
    }
    
    return 0;
}
