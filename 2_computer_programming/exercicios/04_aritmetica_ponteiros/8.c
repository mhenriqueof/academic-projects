# include <stdio.h>

int main() {

    int vetor[] = {1,2,3,4,5,6,7,8,9,};
    int tamanho = sizeof(vetor) / sizeof(vetor[0]);
    int soma = 0, multiplicacao = 1;

    for (int i = 0; i < tamanho; i++) {
        if (i % 2 == 0) {
            soma += *(vetor+i);
        } else {
            multiplicacao *= *(vetor+i);
        }
    }

    printf("Soma: %d\nMultiplicacao: %d\n", soma, multiplicacao);

    return 0;
}
