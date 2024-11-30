# include <stdlib.h>

int **aloca(int linhas, int colunas);
void libera(int **matriz, int linhas);


int **aloca(int linhas, int colunas) {

    int **matriz = (int **) malloc(linhas * sizeof(int *));
    if (matriz == 0) {
        return 0;
    }

    for (int i = 0; i < linhas; i ++) {
        matriz[i] = (int *) malloc(colunas * sizeof(int));
        
        for (int j = 0; j < colunas; j++) {
            matriz[i][j] = rand() % 10;
        }
    }

    return matriz;
}

void libera(int **matriz, int linhas) {

    for (int i = 0; i < linhas; i++) {
        free(matriz[i]);
    }
    free(matriz);
}
