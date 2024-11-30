# include <stdio.h>

void funcao(int *p1, int *p2) {
    *p1 *= 2;
    *p2 *= 2;
}

int main() {

    int a = 2, b = 3;
    int *p1 = &a, *p2 = &b;

    funcao(p1, p2);

    printf("%d - %d", a, b);

    return 0;
}
