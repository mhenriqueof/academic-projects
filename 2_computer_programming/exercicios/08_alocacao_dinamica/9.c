# include <stdio.h>
# include <stdlib.h>
# include <time.h>

int main() {
    srand(time(0));

    int n, m;
    int l = 0, c = 0;

    printf("N: ");
    scanf("%d", &n);

    printf("M: ");
    scanf("%d", &m);

    int **matriz = (int **) malloc(n * sizeof(int *));
    if (matriz == 0) {
        return 1;
    }
    for (int i = 0; i < n; i++) {
        matriz[i] = (int *) malloc(m * sizeof(int));

        for (int j = 0; j < m; j++) {
            matriz[i][j] = rand() % 101 - 50;
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }

    int menor = matriz[0][0], maior = matriz[0][0];
    int cont = 0;

    while (cont != 3) {

        for (int i = 0; i < n; i++) {

                if (cont == 3) {
                    break;
                }

                for (int j = 0; j < m; j++) {

                    if (matriz[i][j] > maior) {
                        maior = matriz[i][j];
                        l = i+1;
                        c = j+1;
                    }

                    if (i == 0) {
                        if (matriz[i][j] < menor) {
                            menor = matriz[i][j];
                        }
                    }
                }

                printf("Maior: %d - Linha: %d, Coluna: %d\n", maior, l, c);
                cont++;
                matriz[l][c] = menor;
                maior = menor;
            }
    }

    for (int i = 0; i < n; i++) {
        free(matriz[i]);
    }
    free(matriz);

    return 0;
}
