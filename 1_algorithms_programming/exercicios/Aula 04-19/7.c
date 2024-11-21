// Crie um algoritmo que leia os limites inferior e superior de umintervalo e imprima todos os números pares no intervalo aberto e seusomatório. Suponha que os números digitados são um intervalo crescente.Exemplo:● Limite inferior: 3● Limite superior: 12● Saída: 4 6 8 10● Soma: 28

#include <stdio.h>

int main() {
    
    int inferior, superior, intervalo, soma = 0;
    
    printf("Limite inferior: ");
    scanf("%d", &inferior);
    
    printf("Limite superior: ");
    scanf("%d", &superior);
    
    intervalo = superior - inferior;
    
    printf("Intervalo numeros pares: ");
    for (int i = inferior+1; i <= superior-1; i++) {
        if (i % 2 == 0) {
            printf("%d ", i);
            soma += i;
        }
    }
    printf("\nSoma: %d", soma);

    return 0;
}