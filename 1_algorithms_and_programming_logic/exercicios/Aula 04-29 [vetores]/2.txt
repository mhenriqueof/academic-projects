#include <stdio.h>

int main() {
    
    int vetor[5] = {45, 13, 8, 9, 95};
    
    for (int i = 0; i < 5; i++) {
        if (i % 2 == 0 && i != 0) {
            printf("%d ", vetor[i]);
        }
    }

    return 0;
}
