# include <stdio.h>
# include <stdlib.h>
# include <time.h>

int *alocar(int tamanho) {

    int *vetor = (int *) calloc(tamanho, sizeof(int));
    if (vetor == 0) {
        exit(1);
    }

    return vetor;
}

void preencher(int *p, int tamanho) {

    srand(time(0));

    for (int i = 0; i < tamanho; i++) {
        *(p + i) = rand() % 10;
    }
}

void imprimir(int *p, int tamanho) {

    for (int i = 0; i < tamanho; i++) {
        printf("%d ", *(p + i));
    }
}


int main() {

    int tamanho;
    printf("Tamanho vetor: ");
    scanf("%d", &tamanho);

    int *p = alocar(tamanho);

    preencher(p, tamanho);

    imprimir(p, tamanho);

    free(p);

    return 0;
}
