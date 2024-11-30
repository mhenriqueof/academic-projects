# include <stdio.h>

int main() {

    char titulo[50];
    scanf("%s", titulo);

    FILE* arquivo = fopen(titulo, "r"); 
    if (arquivo == NULL) {
        printf("Erro.");
        return 1;
    }

    char line[256];
    while (fscanf(arquivo, "%255s", line) != EOF) {
        printf("%s\n", line);
    }

    fclose(arquivo);

    return 0;
}
