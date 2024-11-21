// Leia dois números (a e b) do teclado, tal que a < b, e imprima a tabuada de cada um desses números.○ Por exemplo, se forem lidos os números 3 e 5, apresentar a tabuada do 3, do 4 e do 5 (cadauma de 1 a 10).

#include <stdio.h>

int main() {
    
    int a, b, intervalo;
    
    printf("Valor de A e B [sendo B maior que A: ");
    scanf("%d %d", &a, &b);
    
    if (a > b) {
        return 1;
    }
    
    intervalo = b - a + 1;
    
    for (int i = 1; i <= intervalo; i++) {
        for (int i = 1; i <= 10; i++) {
            printf("%d x %d = %d\n", a, i, a * i);
        }
        printf("---\n");
        a++;
    }
    
    return 0;
}
