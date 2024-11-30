# include <stdio.h>
# include <stdlib.h>

char *alocar(int tamanho) {

    char *string = (char *) malloc((tamanho+1) * sizeof(char));
    if (string == NULL) {
        exit(1);
    }

    return string;
}

int main() {

    int tamanho, *p = &tamanho;

    printf("Tamanho string: ");
    scanf("%d", p);

    char *string = alocar(tamanho);

    fflush(stdin);
    gets(string);

    for (int i = 0; i < tamanho; i++) {
        
        if (string[i] != 'a' && string[i] != 'e' && string[i] != 'i' && string[i] != 'o' && string[i] != 'u') {
            printf("%c", string[i]);
        }
    }

    free(string);

    return 0;
}
