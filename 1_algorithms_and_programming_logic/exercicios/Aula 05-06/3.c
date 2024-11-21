// Defina uma matriz com 3 linhas e 5 colunas e imprima o somatório dos elementos de sua última coluna

# include <stdio.h>

int main() {
    
    int matriz[4][4] = {
        {1, 2, 3, 4},
        {1, 2, 3, 4},
        {1, 2, 3, 4},
        {1, 2, 3, 4},
    };
    int multi = 1;
    
    for (int i = 0; i < 4; i++) {
        
        for (int j = 0; j < 4; j++) {
            if (i == j) {
                multi *= matriz[i][j];
            }
        }
    }
    printf("%d", multi);
    
    return 0;
}
