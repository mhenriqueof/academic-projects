# include <stdio.h>
# include <stdlib.h>
# include <time.h>

void preencher(int *vetor, int tamanho) {

    srand(time(0));

    for (int i = 0; i < tamanho; i++) {
        vetor[i] = rand() % 6 + 1;
    }
}

void contagem(int *vetor, int tamanho) {
    for (int i = 1; i <= 6; i++) {

        int cont = 0; 
        for (int j = 0; j < tamanho; j++) {
            if (vetor[j] == i) {
                cont++;
            }
        }
        printf("Numero de %d na lista e %d\n", i, cont);
    }
}

int main() {

    int tamanho = 1000, numeros[tamanho];

    preencher(numeros, tamanho);

    for (int i = 0; i < tamanho; i++) {
        printf("%d ", numeros[i]);
    }
    printf("\n");

    contagem(numeros, tamanho);

    return 0;
}
