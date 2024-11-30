# include <stdio.h>
# include <stdlib.h>
# include <time.h>

int main() {

    srand(time(0));

    int tamanho = 0;

    printf("Tamanho do vetor: ");
    scanf("%d", &tamanho);

    int *vetor = (int *) malloc(tamanho * sizeof(int));

    if (vetor == 0) {
        return 1;
    }

    for (int i = 0; i < tamanho; i++) {
        *(vetor+i) = rand() % 10;
    }   

    for (int i = 0; i < tamanho; i++) {
        printf("%d ", *(vetor + i));
    }

    free(vetor);

    return 0;
}
