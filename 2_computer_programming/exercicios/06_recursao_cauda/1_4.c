# include <stdio.h>

int primo_aux(int n, int aux, int cont) {

    if (aux == 1) {
        return 1;
    }

    if (n % aux == 0) {
        cont++;
    }

    if (cont == 2) {
        return 0;
    }
    
    return primo_aux(n, aux-1, cont);
}

int primo(int n) {

    return primo_aux(n, n, 0);
}


int main() {

    int n = 5;

    printf("%d", primo(n));

    return 0;
}
