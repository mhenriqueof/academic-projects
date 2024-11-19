#include <stdio.h>

int main() {
    
    int vetor[5] = {45, 13, 8, 9, 95};
    
    for (int i = 4; i >= 0; i--) {
        
        printf("%d ", vetor[i]);
    }

    return 0;
}
