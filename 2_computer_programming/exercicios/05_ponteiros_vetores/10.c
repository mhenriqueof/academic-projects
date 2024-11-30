# include <stdio.h>

void vetoriacao(int tamanho, int *vetor_1, int *vetor_2) {

    int vetor_3[tamanho];

    for (int i = 0; i < tamanho; i++) {
        *(vetor_3+i) = *(vetor_1+i) + *(vetor_2+i);
        printf("%d ", *(vetor_3+i));
    }
}

int main() {

    int tamanho = 3;
    int vetor_1[] = {1,3,5};
    int vetor_2[] = {2,4,6}; 

    vetoriacao(tamanho, vetor_1, vetor_2);

    return 0;
}
