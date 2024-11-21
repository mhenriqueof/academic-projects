#include <stdio.h>

int main() {
    
    int vetor[9], valor, cont = 8, ultimo, soma = 0, procurar, ocorrencias = 0;
    
    for (int i = 0; i < 9; i++) {
        
        while (1) {
            
            printf("%do valor positivo: ", i+1);
            scanf("%d", &valor);
            
            if (valor > 0) {
                vetor[i] = valor;
                break;
            }
            printf("Valor invalido.\n");
        }
        

    }
    
    for (int i = 0; i < 9; i++) {
        printf("%d  ", vetor[i]);
    }
    
    printf("\n");
    
    for (int i = 1; i <= 9; i++) {
        
        if (i == 1) {
            ultimo = vetor[8];
        }
        
        if (i == 9) {
            vetor[0] = ultimo;
        }
        
        vetor[cont] = vetor[8-i];
        cont--;

        }
        
    for (int i = 0; i < 9; i++) {
        printf("%d  ", vetor[i]);
    }
    
    for (int i = 0; i < 9; i++) {
        vetor[i] += i;
    }
    
    printf("\n");
    
    for (int i = 0; i < 9; i++) {
        printf("%d  ", vetor[i]);
    }
    
    printf("\n");
    
    printf("Valor para procurar: ");
    scanf("%d", &procurar);
    
    for (int i = 0; i < 9; i++) {
        if (procurar == vetor[i]) {
            ocorrencias += 1;
        }
    }
    
    printf("Numero de ocorrencias do %d: %d", procurar, ocorrencias);

    return 0;
}
