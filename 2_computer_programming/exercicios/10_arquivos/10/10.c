# include <stdio.h>

int main() {

    FILE *arquivo = fopen("dados.txt", "w");

    for (int i = 0; i < 100; i++) {
        fprintf(arquivo, "%d\n", i+1);
    }

    fclose(arquivo);

    return 0;
}
