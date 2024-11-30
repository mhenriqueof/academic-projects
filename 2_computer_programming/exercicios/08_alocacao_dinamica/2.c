# include <stdio.h>
# include <stdlib.h>
# include <time.h>
# include "2.h"

int main() {

    srand(time(0));

    int m, n;

    printf("Linhas: ");
    scanf("%d", &m);

    printf("Colunas: ");
    scanf("%d", &n);

    int **matriz = aloca(m, n);

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }

    libera(matriz, m);

    return 0;
}
