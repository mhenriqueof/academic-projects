// Leia 2 valores inteiros (A e B). Após, o programa deve mostraruma mensagem "Sao Multiplos" ou "Nao sao Multiplos", indicando se osvalores lidos são múltiplos entre si

#include <stdio.h>

int main() {
    
    int a, b, resto;
    
    printf("A: ");
    scanf("%d", &a);
    
    printf("B: ");
    scanf("%d", &b);
    
    if (a % b != 0) {
        printf("Não são múltiplos.");
    } else {
        printf("São múltiplos.");
    }

    return 0;
}
