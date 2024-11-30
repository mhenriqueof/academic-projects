# include <stdio.h>

int contar(int numero, int *cont) {
    if (numero == 0) {
        return 0;
    }
    *cont += 1;

    return contar(numero/10, cont);
}

int main() {

    int numero = 10, cont = 0;

    contar(numero, &cont);

    printf("%d", cont);

    return 0;
}
