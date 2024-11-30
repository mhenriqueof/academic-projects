# include <stdio.h>
# include <string.h>

int main() {

    char string[20];

    fflush(stdin);
    gets(string);

    int tamanho = strlen(string);

    printf("String: ");
    for (int i = 0; i < tamanho; i++) {
        printf("%c", *(string + i));
    }

    return 0;
}
