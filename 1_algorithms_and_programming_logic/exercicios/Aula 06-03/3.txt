# include <stdio.h>
# include <stdlib.h>
# include <time.h>

void criar(int linhas, int colunas, int matriz[linhas][colunas]) {

    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            matriz[i][j] = rand() % 5 + 1;
        }
    }
}

void somar(int linhas, int colunas, int matriz_1[linhas][colunas], int matriz_2[linhas][colunas], int matriz_soma[linhas][colunas]) {

    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            matriz_soma[i][j] = matriz_1[i][j] + matriz_2[i][j];
            printf("%d ", matriz_soma[i][j]);
        }
        printf("\n");
    }
}

void mostrar(int linhas, int colunas, int matriz[linhas][colunas]) {

    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
}

int main() {

    srand(time(0));

    int linhas = 3, colunas = 3;
    int matriz_1[linhas][colunas], matriz_2[linhas][colunas], matriz_soma[linhas][colunas];

    criar(linhas, colunas, matriz_1);
    printf("Matriz 1\n");
    mostrar(linhas, colunas, matriz_1);

    criar(linhas, colunas, matriz_2);
    printf("Matriz 2\n");
    mostrar(linhas, colunas, matriz_2);

    printf("Matriz soma\n");
    somar(linhas, colunas, matriz_1, matriz_2, matriz_soma);

    return 0;
}
