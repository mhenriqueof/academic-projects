# include <stdio.h>

int maior_aux(int *vetor, int tamanho, int maior) {

    if (tamanho == 0) {
        return maior;
    }

    if (vetor[tamanho - 1] > maior) {
        maior = vetor[tamanho - 1];
    }

    return maior_aux(vetor, tamanho - 1, maior);
}

int maior(int *vetor, int tamanho) {
    
    if (tamanho == 0) {
        return 1;
    }

    return maior_aux(vetor, tamanho, vetor[0]);
}

int main() {

    int vetor[] = {4, 6, 3, 7, 2, 10, 8, 9};
    int tamanho = sizeof(vetor) / sizeof(vetor[0]);

    printf("Maior: %d", maior(vetor, tamanho));

    return 0;
}
