# include <stdio.h>
# include <time.h>
# include <stdlib.h>

int main() {
    srand(time(0));

    int tamanho = 5, vetor[tamanho];

    for (int i = 0; i < tamanho; i++) {
        *(vetor + i) = rand() % 10;
    }

    for (int i = 0; i < tamanho; i++) {
        printf("%d ", *(vetor + i));
    }

    return 0;
}
