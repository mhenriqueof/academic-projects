# include <stdio.h>
# include <stdlib.h>

int main() {

    int linhas, colunas;

    scanf("%d", &linhas);
    scanf("%d", &colunas);

    float **matriz = (float **) malloc(linhas * sizeof(float *));
    if (matriz == NULL) {
        return 1;
    }

    for (int i = 0; i < linhas; i++) {
        matriz[i] = (float *) malloc(colunas * sizeof(float));

        for (int j = 0; j < colunas; j++) {
            scanf("%f", &matriz[i][j]);
        }
    }

    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            printf("%.2f ", matriz[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < linhas; i++) {
        free(matriz[i]);
    }
    free(matriz);

    return 0;
}
