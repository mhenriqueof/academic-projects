# include <stdio.h>

float calcular(int a, int b) {

    float total;

    if (b == 0) {
        total = a * 0.9;
    } else if (a == 0) {
        total = b * 0.9;
    } else {
        total = (a + b) * 0.85;
    }

    return total;
}

int main() {

    int a = 0, b = 0;

    printf("Quantidade A: ");
    scanf("%d", &a);
    a *= 10;

    printf("Quantidade B: ");
    scanf("%d", &b);
    b *= 20;

    float total = calcular(a, b);

    printf("%.2f", total);

    return 0;
}
