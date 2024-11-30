# include <stdio.h>
# include <stdlib.h>
# include <time.h>

int contem(int linhas, int colunas, int **matriz, int valor) {
    
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            if (matriz[i][j] == valor) {
                return 1;
            }            
        }
    }

    return 0;
}

int main() {

    srand(time(0));

    int linhas, colunas;

    scanf("%d", &linhas);
    scanf("%d", &colunas);

    int **matriz = (int **) malloc(linhas * sizeof(int *));
    if (matriz == NULL) {
        return 1;
    }

    for (int i = 0; i < linhas; i++) {
        matriz[i] = (int *) malloc(colunas * sizeof(int));
        if (matriz[i] == NULL) {
            return 1;
        }

        for (int j = 0; j < colunas; j++) {
            matriz[i][j] = rand() % 10;
        }
    }

    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }

    printf("%d", contem(linhas, colunas, matriz, 2));

    for (int i = 0; i < linhas; i++) {
        free(matriz[i]);
    }
    free(matriz);

    return 0;
}
