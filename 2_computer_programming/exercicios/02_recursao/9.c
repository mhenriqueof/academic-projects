# include <stdio.h>

int potenciacao(int base, int expoente) {

    if (expoente == 1) {
        return base;
    }

    return base * potenciacao(base, expoente - 1);
}

int main() {
    
    int a, b;

    printf("Base: ");
    scanf("%d", &a);

    printf("Expoente: ");
    scanf("%d", &b);

    printf("%d", potenciacao(a, b));

    return 0;
}
