# include <stdio.h>

int mdc(int n1, int n2, int divisor) {
    if ((n1 % divisor == 0) & (n2 % divisor == 0)) {
        return divisor;
    }
    return mdc(n1, n2, divisor - 1);
}

int main() {

    int n1, n2, divisor, menor_divisor;

    printf("N1: ");
    scanf("%d", &n1);

    printf("N2: ");
    scanf("%d", &n2);

    divisor = n1;
    if (n2 < divisor) {
        divisor = n2;
    }

    menor_divisor = mdc(n1, n2, divisor);

    printf("%d", menor_divisor);

    return 0;
}
