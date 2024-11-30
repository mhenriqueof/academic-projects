# include <stdio.h>

int intervalo(int a, int b, int *vetor, int tamanho) {

    int maior, menor, cont = 0;

    if (a > b) {
        maior = a;
        menor = b;
    } else {
        maior = b;
        menor = a;
    }

    for (int i = 0; i < tamanho; i++) {
        if ((*(vetor+i) >= menor)  && (*(vetor+i) <= maior)) {
            cont++;
        }
    }

    return cont;
}


int main() {

    int a, b, cont;
    int vetor[] = {2,1,6,7,3,4,9,5};
    int tamanho = sizeof(vetor) / sizeof(vetor[0]);

    scanf("%d", &a);
    scanf("%d", &b);

    cont = intervalo(a, b, vetor, tamanho);

    printf("%d", cont);

    return 0;
}
