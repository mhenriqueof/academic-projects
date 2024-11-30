# include <stdio.h>

void insertion(float vetor[], int tamanho) {
    for (int i = 1; i < tamanho; i++) {
        float atual = vetor[i];
        int j = i - 1;
        while (j >= 0 && vetor[j] > atual) {
            vetor[j+1] = vetor[j];
            j -= 1;
        }
        vetor[j+1] = atual;
    }
}

int main() {

    float vetor[] = {1.73, 1.55, 1.98, 1.70, 1.77, 1.60, 1.59, 1.90};
    int tamanho = sizeof(vetor) / sizeof(vetor[0]);

    for (int i = 0; i < tamanho; i++) {
        printf("%.2f ", vetor[i]);
    }

    printf("\n");

    insertion(vetor, tamanho);

    printf("\n");

    for (int i = 0; i < tamanho; i++) {
        printf("%.2f ", vetor[i]);
    }

    return 0;
}
