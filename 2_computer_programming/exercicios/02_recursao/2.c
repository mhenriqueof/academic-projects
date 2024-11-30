# include <stdio.h>

int binario(int numero, int vetor[], int posicao, int *tamanho) {
    if (numero == 0) {
        *tamanho = posicao;
        return 0;
    }

    vetor[posicao] = numero%2;

    return binario(numero/2, vetor, posicao+1, tamanho);
}

int main() {

    int numero = 10, tamanho;
    int vetor[30];

    binario(numero, vetor, 0, &tamanho);

    while (tamanho != 0) {
        printf("%d", vetor[tamanho-1]);
        tamanho--;
    }

    return 0;
}
