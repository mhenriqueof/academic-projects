# include <stdio.h>

void funcao(int vetor[], int tamanho) {
    int i = 0;
    while (i < tamanho) {
        int temp = vetor[i];
        vetor[i] = vetor[tamanho];
        vetor[tamanho] = temp;
        i++,
        tamanho--;
    }
}

int main() {

    int vetor[] = {1,2,3,4,5};
    int tamanho = sizeof(vetor) / sizeof(vetor[0]);

    funcao(vetor, tamanho-1);

    tamanho = sizeof(vetor) / sizeof(vetor[0]);
    
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", vetor[i]);
    }

    return 0;
}
