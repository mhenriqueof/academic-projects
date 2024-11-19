#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void preencher_numeros(int *vetor, int tamanho) {
    srand(time(NULL));
    int numero;
    for (int i = 0; i < tamanho; i++) {
        vetor[i] = rand() % 5 + 1;;
    }
}

void preencher_letras(int *vetor, int tamanho) {
    for (int i = 0; i < tamanho; ++i) {
        vetor[i] = random() % 26 + 65;
    }
}

void mostrar(int *vezes, int *letras, int tamanho) {
    printf("\n");
    for (int i = 0; i < tamanho; i++) {
        for (int j = 1; j <= vezes[i]; j++) {
            printf("%c", letras[i]);
        }
        printf("\n");
    }
}

int main() {
    
    int tamanho = 5, numeros[tamanho], letras[tamanho];
    
    preencher_numeros(numeros, tamanho);
    printf("Vetor numeros: ");
    for (int i = 0; i < tamanho; i++) {
        printf("%d", numeros[i]);
    }
    
    preencher_letras(letras, tamanho);
    printf("\nVetor letras: ");
    for (int i = 0; i < tamanho; i++) {
        printf("%c", letras[i]);
    }
    
    mostrar(numeros, letras, tamanho);
    
    return 0;
}
