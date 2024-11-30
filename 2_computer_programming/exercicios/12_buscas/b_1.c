# include <stdio.h>

int busca_binaria(int numeros[], int inicio, int fim, int busca) {

    while (inicio <= fim) {
        int meio = inicio + (fim - inicio) / 2;

        if (numeros[meio] == busca) {
            return meio;
        } else if (numeros[meio] > busca) {
            fim = meio - 1;
        } else {
            inicio = meio + 1;
        }
    }

    return -1;
}

int main() {

    int numeros[] = {2, 4, 6, 8, 10, 12, 14, 16, 18, 20};
    int tamanho = sizeof(numeros) / sizeof(numeros[0]), encontrado, busca = 10;

    encontrado = busca_binaria(numeros, 0, tamanho-1, busca);

    if (encontrado == -1) {
        printf("Numero %d nao encontrado.", busca);
    } else {
        printf("Numero %d encontrado na posicao %d", busca, encontrado);
    }

    return 0;
}
