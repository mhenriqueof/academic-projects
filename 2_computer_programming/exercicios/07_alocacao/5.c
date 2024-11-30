# include <stdio.h>
# include <stdlib.h>

int main() {

    int tamanho;

    printf("Tamanho vetor: ");
    scanf("%d", &tamanho);

    int *vetor = (int *) malloc(tamanho * sizeof(int));
    if (vetor == NULL) {
        return 1;
    }

    for (int i = 0; i < tamanho; i++) {
        printf("Valor %d: ", i+1);
        scanf("%d", vetor+i);
    }

    for (int i = 0; i < tamanho; i++) {
        printf("%d ", *(vetor+ i));
    }

    free(vetor);

    return 0;
}
