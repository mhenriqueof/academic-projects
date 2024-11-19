#include <stdio.h>
#include <string.h>

int main() {
    char originalString[] = "Esta é uma string com espaços";
    char novaString[100]; // Tamanho suficiente para a nova string

    int i, j = 0;

    // Percorre a string original
    for (i = 0; i < strlen(originalString); i++) {
        if (originalString[i] != ' ') {
            novaString[j] = originalString[i];
            j++;
        }
    }

    // Adiciona o caractere nulo de terminação à nova string
    novaString[j] = '\0';

    // Imprime a nova string
    printf("Nova string sem espaços: %s\n", novaString);

    return 0;
}