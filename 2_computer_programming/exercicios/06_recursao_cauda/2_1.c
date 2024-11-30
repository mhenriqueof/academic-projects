# include <stdio.h>

float soma(float *vetor, int tamanho) {

    if (tamanho == 0) {
        return 0;
    }

    return vetor[0] + soma(vetor + 1, tamanho - 1);
}

int main() {

    float valores[] = {1.0, 2.0, 3.0, 4.0, 5.0, 10.0};
    int tamanho = sizeof(valores) / sizeof(valores[0]);
    printf("Soma: %.2f", soma(valores, tamanho));

    return 0;
}
