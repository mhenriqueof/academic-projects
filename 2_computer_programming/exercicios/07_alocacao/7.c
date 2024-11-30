# include <stdio.h>
# include <stdlib.h>

int main() {

    int tamanho, pares = 0, impares = 0;
    scanf("%d", &tamanho);

    int *vetor = (int *) malloc(tamanho * sizeof(int));

    for (int i = 0; i < tamanho; i++) {
        scanf("%d", vetor+i);
    }

    for (int i = 0; i < tamanho; i++) {
        if (*(vetor+i) % 2 == 0) {
            pares++;
        } else {
            impares++;
        }
    }

    free(vetor);

    printf("Pares: %d\nImpares: %d\n", pares, impares);
}
