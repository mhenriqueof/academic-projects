# include <stdio.h>
# include <stdlib.h>
# include <time.h>

int main() {

    srand(time(0));
    int matriz[4][4], transposta[4][4];

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            matriz[i][j] = rand() % 10;
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }

    printf("\n");

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            transposta[j][i] = matriz[i][j];
        }
    }

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            printf("%d ", transposta[i][j]);
        }
        printf("\n");
    }
}
