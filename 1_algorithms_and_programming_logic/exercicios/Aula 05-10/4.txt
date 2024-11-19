# include <stdio.h>
# include <time.h>
# include <stdlib.h>

int main() {
    
    int matriz[10][15], soma_linhas = 0, soma_colunas = 0;
    srand(time(0));

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 15; j++) {
            matriz[i][j] = rand() % 101;
            printf("%d ", matriz[i][j]);
            soma_linhas += matriz[i][j];
            }
        printf(" = %d | ", soma_linhas);
        if (soma_linhas % 2 == 0) {
            printf("A soma dos elementos da linha e par");
        } else {
            printf("A soma dos elementos da linha e impar");
        }  
        printf("\n");
    }
    for (int j = 0; j < 15; j++) {
        for (int i = 0; i < 10; i++) {
            soma_colunas += matriz[i][j];
        }
        printf("%d | ", soma_colunas);

        if (soma_colunas % 2 == 0) {
            printf("A soma dos elementos da coluna %d e par.", j);
        } else {
            printf("A soma dos elementos da coluna %d e impar.", j);
        }
        printf("\n");
    }

    return 0;
}
