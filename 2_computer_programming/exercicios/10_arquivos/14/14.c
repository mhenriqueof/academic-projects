# include <stdio.h>

int main() {

    FILE *arquivo = fopen("arq.txt", "r");

    int contador = 0;
    char linha[100];
    while(fgets(linha, sizeof(linha), arquivo) != NULL) {
        contador++;
    }
    
    fclose(arquivo);

    printf("%d", contador);

    return 0;
}
