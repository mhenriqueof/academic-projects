# include <stdio.h>

void checar(int valor) {

    int soma = 0;
    for (int i = 1; i < valor; i++) {
        if (valor % i == 0) {
            soma += i;
        }
    }
    printf("\n---\n");
    if (soma == valor) {
        printf("Perfeito.");
    } else {
        printf("Nao perfeito.");
    }
}

int main() {
    
    int n;

    scanf("%d", &n);
    checar(n);

    return 0;
}
