// Defina uma matriz com 3 linhas e 5 colunas e imprima o somatório dos elementos de sua última coluna

# include <stdio.h>

int main() {
    
    int matriz[3][5] = {
        {1, 2, 3, 4, 5},
        {1, 2, 3, 4, 5},
        {1, 2, 3, 4, 5}
    };
    int soma = 0;
    
    for (int i = 0; i < 3; i++) {
        
        soma += matriz[i][4];
        
    }
    printf("%d", soma);
    
    return 0;
}
