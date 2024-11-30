# include <stdio.h>

int main() {

    int vetor[5];

    for (int i = 0; i < 5; i++) {
        printf("Posicao %d: ", i+1);
        scanf("%d", vetor+i);
    }
    
    for (int i = 0; i < 5; i++) {
        printf("%d ", *(vetor+i) * 2);
    }
}
