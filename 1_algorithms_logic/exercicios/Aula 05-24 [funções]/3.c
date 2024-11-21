# include <stdio.h>

void conver(double valor) {

    double fahr = (valor * 9 / 5) + 32;
    printf("%.2f", fahr);
}

int main() {

    double cels;

    scanf("%lf", &cels);

    conver(cels);

    return 0;
}
