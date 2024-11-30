# include <stdio.h>

int max_aux(int n, int *vetor, int maior) {
    if (n == 0) {
        return maior;
    }

    if (vetor[n-1] > maior) {
        maior = vetor[n-1];
    }

    return max_aux(n-1, vetor, maior);
}

int max(int n, int *vetor) {
    return max_aux(n, vetor, vetor[0]);
}

int main() {

    int vetor[] = {5,6,1,8,3,9};
    int n = sizeof(vetor)/sizeof(vetor[0]);
    int *v = vetor;

    printf("Maior: %d", max(n, v));

}
