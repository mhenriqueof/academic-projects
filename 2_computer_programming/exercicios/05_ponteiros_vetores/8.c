# include <stdio.h>

int main() {

    int vetor[10], *p = vetor;
    int tamanho = sizeof(vetor) / sizeof(vetor[0]);

    for (int i = 0; i < tamanho; i++) {
        printf("%d: ", i+1);
        scanf("%d", p+i);
    }

    for (int i = tamanho; i > 0; i--) {
        printf("%d ", vetor[i - 1]);
    }
}
