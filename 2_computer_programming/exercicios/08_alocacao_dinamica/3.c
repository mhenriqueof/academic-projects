# include <stdio.h>
# include <stdlib.h>
# include <time.h>

int **aloca(int linhas, int colunas) {

    int **matriz = (int **) malloc(linhas * sizeof(int *));
    if (matriz == 0) {
        return 0;
    }

    matriz[0] = (int *) malloc(linhas * colunas * sizeof(int));
    if (matriz[0] == 0) {
        return 0;
    }

    for (int i = 0; i < linhas; i++) {
        matriz[i] = matriz[0] + i * colunas;
    }

    return matriz;
}

void libera(int **matriz) {
    free(matriz[0]);
    free(matriz);
}

int main() {

    srand(time(0));

    int linhas = 4, colunas = 5;

    int **matriz = aloca(linhas, colunas);

    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            matriz[i][j] = rand() % 10;
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }

    libera(matriz);

    return 0;
}
