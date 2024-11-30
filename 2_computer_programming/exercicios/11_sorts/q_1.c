# include <stdio.h>

int particiona(float vetor[], int inicio, int fim) {
    float pivo = vetor[fim];
    int i = inicio - 1;

    for (int j = inicio; j < fim; j++) {
        if (vetor[j] < pivo) {
            i++;
            float temp = vetor[i];
            vetor[i] = vetor[j];
            vetor[j] = temp;
        }
    }
    float temp = vetor[i+1];
    vetor[i+1] = vetor[fim];
    vetor[fim] = temp;

    return i+1;
}

void quick_sort(float vetor[], int inicio, int fim) {
    if (inicio < fim) {
        int pivo = particiona(vetor, inicio, fim);
        quick_sort(vetor, inicio, pivo-1);
        quick_sort(vetor, pivo+1, fim);
    }
}

int main() {

    float vetor[] = {0.57, 0.48, 0.50, 0.51, 0.47, 0.47, 0.33, 0.31, 0.32};
    int tamanho = sizeof(vetor) / sizeof(vetor[0]);


    for (int i = 0; i < tamanho; i++) {
        printf("%.2f ", vetor[i]);
    }

    printf("\n");

    quick_sort(vetor, 0, tamanho-1);

    printf("\n");

    for (int i = 0; i < tamanho; i++) {
        printf("%.2f ", vetor[i]);
    }

    return 0;
}
