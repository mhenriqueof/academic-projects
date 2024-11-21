# include <stdio.h>
# include <time.h>
# include <stdlib.h>

int main() {

    int n_aleatorio, vetor[1000], n, posicao = -1;
    srand(time(NULL));

    for (int i = 0; i < 1000; i++) {
        n_aleatorio = rand() % 1001;
        vetor[i] = n_aleatorio;
        printf("%d ", vetor[i]);
    }

    printf("Numero a verificar: ");
    scanf("%d", &n);

    for (int i = 0; i < 1000; i++) {
        if (n == vetor[i]) {
            posicao = i;
        }
    }

    if (posicao == -1) {
        printf("Nao houve ocorrencia.");
    } else {
        printf("Ultima ocorrencia na posicao: %d", posicao);
    }

    return 0;
}
