// Escreva um algoritmo que leia vários números e informe quantosnúmeros entre 100 e 200 foram digitados. Quando o valor 0 (zero) for lido, oalgoritmo deverá cessar sua execução

#include <stdio.h>

int main() {
    
    int cont = 1, cont_intervalo;
    float numero = 1;
    
    while (numero != 0) {
        
        printf("Valor %d: ", cont);
        scanf("%f", &numero);
        
        if (numero >= 100 && numero <= 200) {
            cont_intervalo++;
        }
        
        cont++;
    }
    printf("%d numeros entre 100 e 200 foram digitados.\n", cont_intervalo);
    
    return 0;
}
