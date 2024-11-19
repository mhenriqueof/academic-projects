# include <stdio.h>

int main() {


    int linhas = 3, colunas = 3, valor, x;
    int matriz[linhas][colunas];

    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            printf("Valor para M(%d,%d): ", i+1, j+1);
            scanf("%d", &valor);
            matriz[i][j] = valor;
        }
    }

    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }

    printf("Numero X: ");
    scanf("%d", &x);

    printf("Os valores multiplos de %d sao: ", x);
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            if (matriz[i][j] % x == 0) {
                printf("%d ", matriz[i][j]);
            }
        }
    }

    return 0;
}
