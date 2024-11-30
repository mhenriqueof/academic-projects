# include <stdio.h>

int main() {

    //12
    FILE *arquivo = fopen("arq.txt", "w+");

    char carac;
    while (carac != '0') {
        scanf(" %c", &carac);
        fprintf(arquivo, "%c\n", carac);
    }

    //13
    fseek(arquivo, 0, SEEK_SET);

    int vogais = 0;
    char linha;
    while(fscanf(arquivo, "%c", &linha) != EOF) {
        printf("%c", linha);
        if (linha == 'a' || linha == 'e' || linha == 'i' || linha == 'o' || linha == 'u') {
            vogais += 1;
        }
    }

    fclose(arquivo);

    printf("\n%d", vogais);

    return 0;
}
