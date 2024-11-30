# include <stdio.h>

void selection(float vetor[], int tamanho) {
    float menor;
    int posicao_menor;

    for (int i = 0; i < tamanho; i++) {
        menor = vetor[i];
        posicao_menor = i;
        
        for (int j = i; j < tamanho; j++) {
            if (vetor[j] < menor) {
                menor = vetor[j];
                posicao_menor = j;
            }
        }
        float temp = vetor[i];
        vetor[i] = vetor[posicao_menor];
        vetor[posicao_menor] = temp;
    }
}

int main() {

    float vetor[] = {1.57, 0.75, 78.94, 15.67, 17.45, 10.13, 20.15};
    int tamanho = sizeof(vetor) / sizeof(vetor[0]);

    for (int i = 0; i < tamanho; i++) {
        printf("%.2f ", vetor[i]);
    }

    selection(vetor, tamanho);

    printf("\n");

    for (int i = 0; i < tamanho; i++) {
        printf("%.2f ", vetor[i]);
    }

    return 0;
}
