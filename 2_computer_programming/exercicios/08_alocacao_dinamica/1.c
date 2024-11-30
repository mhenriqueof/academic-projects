# include <stdio.h>
# include <stdlib.h>
# include <time.h>

int main() {

    srand(time(0));

    int ordem = 0;
    double **p;

    printf("Ordem da matriz: ");
    scanf("%d", &ordem);

    p = (double **) malloc(ordem * sizeof(double *));
    for (int i = 0; i < ordem; i++) {
        p[i] = (double *) malloc(ordem * sizeof(double));

        for (int j = 0; j < ordem; j++) {
            p[i][j] = rand() % 10;
        }
    }

    for (int i = 0; i < ordem; i++) {
        for (int j = 0; j < ordem; j++) {
            printf("%.2f ", p[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < ordem; i++) {
        free(p[i]);
    }
    free(p);

    return 0;
}
