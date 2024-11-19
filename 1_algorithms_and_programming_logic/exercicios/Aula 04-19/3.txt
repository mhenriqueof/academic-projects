// Faça um programa que leia n números e, para cada dessesnúmeros, diga se é primo ou não. Pare a repetição quando for lido um número negativo

# include <stdio.h>

int main() {

    int n = 1;
    
    do {
        int cont = 0;

        printf("Numero: ");
        scanf("%d", &n);

        for (int i = 1; i <= n; i++) {

            if (n % i == 0) {
                cont++;
            }
        }
        if (cont == 2) {
            printf("Ele e primo.\n");
        } else {
            printf("Ele nao e primo.\n");
        }

    } while (n > 0);
}
