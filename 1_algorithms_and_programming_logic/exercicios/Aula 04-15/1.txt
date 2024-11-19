// Desenvolver um algoritmo que efetue a soma de todos os números ímpares que são múltiplos detrês e que se encontram no conjunto dos números de 1 até 500

#include <stdio.h>

int main() {
    
    int resultado;
    
    for (int i = 2; i <= 500; i++) {
        if (i % 2 != 0) {
            if (i % 3 == 0) {
                resultado += i;
            }
        }
    }
    printf("Soma: %d", resultado);
    
    return 0;
}
