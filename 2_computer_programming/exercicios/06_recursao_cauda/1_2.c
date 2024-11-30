# include <stdio.h>

int pertence_aux(int numero, int *vetor, int tamanho) {
    if (tamanho == 0) {
        return 0;
    }

    if (numero == vetor[tamanho - 1]) {
        return 1;
    }

    return (pertence_aux(numero, vetor, tamanho - 1));
}

int pertence(int numero, int *vetor, int tamanho) {
    if (tamanho == 0) {
        return 0;
    }

    return pertence_aux(numero, vetor, tamanho);
}

int main() {

    int numero = 20, vetor[] = {5,4,2,3,9,6}, *p = vetor;    
    int tamanho = sizeof(vetor) / sizeof(vetor[0]);

    printf("%d", pertence(numero, p, tamanho));

}
