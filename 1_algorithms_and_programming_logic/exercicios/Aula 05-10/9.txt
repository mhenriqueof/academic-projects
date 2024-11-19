# include <stdio.h>
# include <stdlib.h>
# include <time.h>

int main() {

    srand(time(0));

    int linhas = 3, colunas = 4;
    float matriz[linhas][colunas], vetor_linhas[linhas], vetor_colunas[colunas];

    for (int i = 0; i < linhas; i++) {

        float soma_linhas = 0;
        for (int j = 0; j < colunas; j++) {
            matriz[i][j] = rand() % 5 + 1;
            printf("%.1f ", matriz[i][j]);

            soma_linhas += matriz[i][j];
        }
        vetor_linhas[i] = soma_linhas;
        printf("\n");
    }

    for (int i = 0; i < colunas; i++) {

        float soma_colunas = 1;
        for (int j = 0; j < linhas; j++) {
            soma_colunas *= matriz[j][i];
        }
        vetor_colunas[i] = soma_colunas;
    }

    printf("Vetor linhas: ");
    for (int i = 0; i < linhas; i++) {
        printf("%.1f ", vetor_linhas[i]);
    }

    printf("\nVetor colunas: ");
    for (int i = 0; i < colunas; i++) {
        printf("%.1f ", vetor_colunas[i]);
    }

    return 0;
}
