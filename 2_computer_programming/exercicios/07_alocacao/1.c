# include <stdio.h>
# include <stdlib.h>

int main() {


    int tamanho = 5;
    int *vetor = (int *) malloc(tamanho * sizeof(int));

    for (int i = 0; i < tamanho; i++) {
        printf("Numero %d: ", i+1);
        scanf("%d", vetor+i);
    }

    for (int i = 0; i < tamanho; i++) {
        printf("%d", *(vetor + i));
    }

    free(vetor);

    return 0;
}
