#include <stdio.h>

int main() {
    
    float vetorA[4], vetorB[4], resultado = 0;
    
    for (int i = 0; i < 4; i++) {
        printf("Valor %d do vetor A e B: ", i);
        scanf("%f%f", &vetorA[i], &vetorB[i]);
        
        printf("Subtração no indice %d: %.2f\n", i, vetorA[i] - vetorB[i]);
        
        resultado += vetorA[i] - vetorB[i];
    }
    printf("%.2f", resultado);
    
    return 0;
}
