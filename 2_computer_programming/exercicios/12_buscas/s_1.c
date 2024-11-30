# include <stdio.h>

int buscar_arquivo(int busca) {
    FILE *arquivo = fopen("s_1.txt", "r");

    int valor, linha = 0;
    while (fscanf(arquivo, "%d", &valor) != EOF) {
        if (valor == busca) {
            fclose(arquivo);
            return linha;
        }
        printf("%d - %d\n", linha, valor);
        linha += 1;
    }

    fclose(arquivo);
    return -1;
}

int main() {

    int busca, encontrado;

    scanf("%d", &busca);

    encontrado = buscar_arquivo(busca);

    if (encontrado != -1) {
        printf("Numero %d esta na linha %d.", busca, encontrado);
    } else {
        printf("Numero %d nao encontrado.", busca);
    }

    return 0;
}
