# include <stdio.h>

void checar(int n) {
    if (n % 2 == 0 || n % 3 == 0) {
        printf("Divisivel 3 ou 2.");
    } else {
        printf("Valor invalido.");
    }
}

int main() {

    int n;

    scanf("%d", &n);

    checar(n);

    return 0;
}
