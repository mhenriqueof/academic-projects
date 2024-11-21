# include <stdio.h>

int main() {

    int vetor_1[4], vetor_2[4], n;

    for (int i = 0; i < 4; i++) {

        while (1) {

            printf("%do valor inteiro, par e positivo: ", i+1);
            scanf("%d", &n);

            if (n % 2 == 0 && n >= 0) {
                vetor_1[i] = n;
                break;
            }
            printf("Numero nao e par ou positivo.\n");
        }
    }
    
    for (int i = 0; i < 4; i++) {

        if (i % 2 == 0) {
            vetor_2[i] = vetor_1[i] / 2;
        } else {
            vetor_2[i] = vetor_1[i] * 3;
        }
    }

    printf("Vetor inicial: ");
    for (int i = 0; i < 4; i++) {

        printf("%d ", vetor_1[i]);
    }

    printf("\nVetor final: ");
    for (int i = 0; i < 4; i++) {

        printf("%d ", vetor_2[i]);
    }

    return 0;
}
