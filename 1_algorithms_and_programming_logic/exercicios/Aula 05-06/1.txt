// Crie uma matriz de 11 linhas e 11 colunas que contenha a tabuada dos números de 0 a 10

# include <stdio.h>

int main() {
    
    int matriz[11][11];
    
    for (int i = 0; i < 11; i++) {
        
        for (int j = 0; j < 11; j++) {
            matriz[i][j] = i * j;
        }
    }
    
    for (int i = 0; i < 11; i++) {
        
        printf("Tabuada do %2d -", i);
        
        for (int j = 0; j < 11; j++) {
            printf("%2d ", matriz[i][j]);
        }
        printf("\n");
    } 

    return 0;
}
