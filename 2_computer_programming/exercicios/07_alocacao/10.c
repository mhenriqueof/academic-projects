# include <stdio.h>
# include <stdlib.h>
# include <time.h>

int main() {
    srand(time(0));

    int tamanho;
    printf("Quantidade alunos: ");
    scanf("%d", &tamanho);

    float *notas = (float *) malloc(tamanho * sizeof(float));
    if (notas == 0) {
        return 1;
    }
    
    float total = 0;

    for (int i = 0; i < tamanho; i++) {
        *(notas + i) = rand() % 11;
        printf("%.2f ", *(notas + i));
        total += *(notas + i);
    }

    printf("\n");

    printf("Media: %.2f", total/tamanho);

    return 0;
}
