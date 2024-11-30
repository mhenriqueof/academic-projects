# include <stdio.h>
# include <string.h>

void inverter(char *string, int inicio, int fim) {

    if (inicio >= fim) {
        return;
    }

    char temp = string[inicio];
    string[inicio] = string[fim];
    string[fim] = temp;

    return inverter(string, inicio + 1, fim - 1);
}

int main() {

    char string[] = "pao no ceu tem";
    int tamanho = strlen(string);

    inverter(string, 0, tamanho-1);

    printf("%s", string);

    return 0;
}
