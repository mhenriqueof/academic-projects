# include <stdio.h>
# include <stdlib.h>
# include <time.h>


int lancar() {
   
    int moeda;
    moeda = rand() % 2;

    return moeda;
}

float n_cara(int lancamentos) {

    int cara = 0, moeda;

    for (int i = 0; i < lancamentos; i++) {
        
        moeda = lancar();
        printf("%d ", moeda);

        if (moeda == 0) {
            cara += 1;
        }

    }
    return cara;
}

int main() {

    srand(time(0));

    int lancamentos;
    float cara, coroa;

    printf("Numero lancamentos: ");
    scanf("%d", &lancamentos);

    cara = n_cara(lancamentos);
    coroa = lancamentos - cara;

    printf("\nPorcentagem cara: %.2f\nPorcentagem coroa: %.2f", (cara * 100) / lancamentos, (coroa * 100) / lancamentos);

    return 0;
}
