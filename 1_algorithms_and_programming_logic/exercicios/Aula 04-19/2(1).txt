// Construa um algoritmo que receba um número inteiro e verifiquese o mesmo é primo

# include <stdio.h>

int main() {

    int n, cont = 0;

    printf("Numero: ");
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {

        if (n % i == 0) {
            cont++;
        }
    }
    if (cont == 2) {
        printf("Ele e primo.");
    } else {
        printf("Ele nao e primo.");
    }
}
