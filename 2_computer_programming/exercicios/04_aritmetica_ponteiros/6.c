# include <stdio.h>

int main() {

    int tamanho = 10, vetor[tamanho], cont = 0;

    for (int i = 0; i < tamanho; i++) {
        printf("%d: ", i+1);
        scanf("%d", vetor+i);
    }

    printf("Valores pares: ");
    for (int i = 0; i < tamanho; i++) {
        if ((*(vetor+i)) % 2 == 0) {
            printf("%d ", *(vetor+i));
            cont++;
        }
    }

    printf("\n");
    printf("Quantidade pares: %d", cont);

    return 0;
}
