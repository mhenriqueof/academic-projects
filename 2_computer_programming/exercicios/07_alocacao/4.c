# include <stdio.h>
# include <stdlib.h>
# include <string.h>

int main() {

    int tamanho = 0;
    char string[50];

    fflush(stdin);
    printf("String: ");
    gets(string);

    tamanho = strlen(string);
    char *string_p = (char *) malloc(tamanho * sizeof(char));

    for (int i = 0; i < tamanho; i++) {
        string_p[i] = string[i];
    }

    printf("%s", string);

    return 0;
}
