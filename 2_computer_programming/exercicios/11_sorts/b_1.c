# include <stdio.h>

void bubble(int vetor[], int tamanho) {
    for (int i = 0; i < tamanho-1; i++) {
        for (int j = 0; j < tamanho-1-i; j++) {
            if (vetor[j] > vetor[j+1]) {
                int temp = vetor[j];
                vetor[j] = vetor[j+1];
                vetor[j+1] = temp;
            }
        }
    }
}

int main() {

    int vetor[] = {1,8,4,7,3,2,6,5,9,0,-5,-3,32,21};
    int tamanho = sizeof(vetor) / sizeof(vetor[0]);

    printf("%d\n", tamanho);

    bubble(vetor, tamanho);

    printf("%d\n", tamanho);

    for (int i = 0; i < tamanho; i++) {
        printf("%d ", vetor[i]);
    }
    
    return 0;
}
