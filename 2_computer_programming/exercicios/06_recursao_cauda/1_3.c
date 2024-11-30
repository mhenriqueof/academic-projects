# include <stdio.h>

int ocorrencias_aux(int numero, int *vetor, int tamanho, int vezes) {
    
    if (tamanho == 0) {
        return vezes;
    }

    if (numero == *(vetor + (tamanho - 1))) {
        vezes += 1;
    }

    return ocorrencias_aux(numero, vetor, tamanho - 1, vezes);

}

int ocorrencias(int numero, int *vetor, int tamanho) {
    return ocorrencias_aux(numero, vetor, tamanho, 0);
}

int main() {

    int numero, vetor[] = {5,1,3,7,9,4,2,5,5,5}, tamanho = sizeof(vetor)/sizeof(vetor[0]);
    int *p = vetor;

    printf("Numero: ");
    scanf("%d", &numero);

    printf("%d", ocorrencias(numero, p, tamanho));

    return 0;
}
