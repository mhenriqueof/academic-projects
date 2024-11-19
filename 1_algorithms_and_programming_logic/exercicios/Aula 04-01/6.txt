// (Beecrowd | 1037) Escreva um programa que leia um valorqualquer e apresente uma mensagem dizendo em qual dos seguintesintervalos [0,25], (25,50], (50,75], (75,100] esse valor se encontra. Se o valornão estiver em nenhum destes intervalos, deverá ser impressa a mensagem“Fora de intervalo”. O símbolo ( representa "maior que". Por exemplo:[0,25] indica valores entre 0 e 25.0000, inclusive eles.(25,50] indica valores maiores que 25 Ex: 25.00001 até o valor 50.0000000

#include <stdio.h>

int main() {
    
    float n;
    
    printf("Número: ");
    scanf("%f", &n);
    
    if (n > 100 || n < 0) {
        printf("Número inválido.");
    } else if (n > 75) {
        printf("O número %.2f se encontra no interlavo (75,100].", n);
    } else if (n > 50) {
        printf("O número %.2f se encontra no interlavo (50,75].", n);
    } else if (n > 25) {
        printf("O número %.2f se encontra no interlavo (25,75].", n);
    } else {
        printf("O número %.2f se encontra no interlavo [0,25].", n);
    }

    return 0;
}
