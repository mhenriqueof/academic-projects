# include <stdio.h>

float soma(float vetor[], int tamanho) {
    if (tamanho == -1) {
        return 0;
    }
    return vetor[tamanho] + soma(vetor, tamanho-1);
}

int main() {

    float vetor[] = {3.14, 2.71, 1.62, 0.58, 4.20};
    int tamanho = sizeof(vetor) / sizeof(vetor[0]);

    printf("%.2f", soma(vetor, tamanho));

    return 0;
}
