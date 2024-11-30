# include <stdio.h>
# include <stdlib.h>

int main() {

    int tamanho;
    scanf("%d", &tamanho);

    int *vetor = (int *) malloc(tamanho * sizeof(vetor));
    if (vetor == NULL) {
        return 1;
    }

    for (int i = 0; i < tamanho; i++) {
        *(vetor+i) = 100*i;
    }

    for (int i = 0; i < tamanho; i++) {
        printf("%d ", *(vetor+i));
    }

    free(vetor);

    return 0;
}
