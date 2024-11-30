# include <stdio.h>

int maior(int *vetor, int tamanho) {
    
    int maior = *(vetor+0);

    for (int i = 0; i < tamanho; i++) {
        if (*(vetor + i) > maior) {
            maior = *(vetor + i);
        }
    }

    return maior;
}


int main() {

    int vetor[] = {2,4,1,3,10,7,2};
    int *p = vetor;

    int tamanho = sizeof(vetor) / sizeof(vetor[0]);
    printf("%d", maior(p, tamanho));

    return 0;
}
