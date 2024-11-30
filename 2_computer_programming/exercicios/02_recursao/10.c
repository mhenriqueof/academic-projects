#include <stdio.h>

void imprimirInverso(int n) {

    int num;

    if (n == 0) {
        return;
    }

    scanf("%d", &num);
    imprimirInverso(n - 1);
    printf("%d ", num);
}

int main() {

    int n;

    printf("Digite o número de elementos: ");
    scanf("%d", &n);
    printf("Digite a sequência de números:\n");
    imprimirInverso(n);
    
    return 0;
}
