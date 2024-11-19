/* Defina uma matriz com 3 linhas e 4 colunas. Crie um vetor com 3 posições que contenha a soma
dos valores de cada uma das linhas da matriz. Crie um vetor com 4 posições que contenha a
multiplicação dos valores de cada uma das colunas da matriz. Ao final do processamento, imprima
esses vetores. */

# include <stdio.h>

int main() {
    
    int matriz[3][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 8, 7, 6}
    };
    int linha[3] = {0, 0, 0}, coluna[4] = {1, 1, 1, 1};
    
    for (int i = 0; i < 3; i++) {
        
        for (int j = 0; j < 4; j++) {
            linha[i] += matriz[i][j];
        }
    }
    
    for (int i = 0; i < 4; i++) {
        
        for (int j = 0; j < 3; j++) {
            coluna[i] *= matriz[j][i];
        }
    }
    
    printf("Vetor linha: ");
    for (int i = 0; i < 3; i++) {
        printf("%d ", linha[i]);
    }
    
    printf("\nVetor coluna: \n");
    for (int i = 0; i < 4; i++) {
        printf("%d\n", coluna[i]);
    }
    
    return 0;
}
