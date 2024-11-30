# include <stdio.h>
# include <stdlib.h>
# include <time.h>

int main() {

    srand(time(0));

    int n, n_achar, cont = 0;

    printf("N elementos: ");
    scanf("%d", &n);

    printf("Achar: ");
    scanf("%d", &n_achar);

    int *vetor = (int *) malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        *(vetor+i) = rand() % 10;
        printf("%d ", *(vetor+i));
    }

    printf("\n");

    for (int i = 0; i < n; i++) {
        if (*(vetor+i) == n_achar) {
            cont++;
        }
    }

    printf("Multiplos de %d: ", n_achar);
    for (int i = 0; i < n; i++) {
        if (*(vetor+i) % n_achar == 0) {
            if (*(vetor+i) == 0 || *(vetor+i) == n_achar) {
                continue;
            }
            printf("%d ", *(vetor+i));
        }
    }

    printf("\n");

    printf("Vezes de %d no array: %d", n_achar, cont);

    return 0;
}
