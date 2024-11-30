# include <stdio.h>

int main() {

    FILE *arquivo = fopen("dados.bin", "wb+");

    for (int i = 0; i < 100; i++) {
        fprintf(arquivo, "%d\n", i+1);
    }

    fseek(arquivo, 0, SEEK_SET);

    char string[100];
    while(fgets(string, sizeof(string), arquivo) != NULL) {
        printf("%s", string);
    }

    fclose(arquivo);
    return 0;
}
