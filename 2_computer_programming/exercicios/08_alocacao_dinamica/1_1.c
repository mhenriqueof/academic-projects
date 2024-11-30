# include <stdio.h>
# include <stdlib.h>

int main() {

    int linhas, colunas;

    printf("Linhas: ");
    scanf("%d", &linhas);

    printf("Colunas: ");
    scanf("%d", &colunas);

    int **matriz1 = (int**) malloc(linhas * sizeof(int*));

    for (int i = 0; i < linhas; i++) {
        matriz1[i] = (int*) malloc(colunas * sizeof(int));
        for (int j = 0; j < colunas; j++) {
            matriz1[i][j] = 10 * (i+1) + j+1;
        }
    }

    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            printf("%d ", matriz1[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < linhas; i++) {
        free(matriz1[i]);
    }
    free(matriz1);

    return 0;
}
