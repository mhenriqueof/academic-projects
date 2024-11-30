#include <stdio.h>

int main() {
    int vetor[] = {1, 2, 3, 4, 5};
    int *p = vetor;

    int tamanho = sizeof(vetor) / sizeof(vetor[0]);
    printf("Tamanho do vetor: %d\n", tamanho);

    for (int i = 0; i < tamanho; i++) {
        *(p + i) = (*(p + i)) + 1;
        printf("%d ", *(p + i));
    }

    return 0;
}
