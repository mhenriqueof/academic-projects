# include <stdio.h>
# include <stdlib.h>
# include <time.h>

int main() {

    srand(time(0));

    float matriz[5][5], vetor[5];

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            matriz[i][j] = rand() % 11;
            printf("%.1f ", matriz[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (i == j) {
                vetor[i] = matriz[i][j];
            }
        }
    }

    for (int i = 0; i < 5; i++) {
        printf("%.1f ", vetor[i]);
    }
    return 0;
}
