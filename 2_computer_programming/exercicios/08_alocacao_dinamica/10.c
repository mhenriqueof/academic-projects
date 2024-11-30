# include <stdio.h>
# include <stdlib.h>

int main() {

    int valor = -1, cont = 0, tamanho = 0;

    int *vetor = (int *) calloc(10, sizeof(int));
    if (vetor == NULL) {
        printf("Erro ao alocar.");
        return 1;
    }
    
    while (1) {

        if (cont == 10) {
            realloc(vetor, 10 * sizeof(int));
            cont = 0;
            for (int i = 0; i < tamanho; i++) {
                printf("%d ", *(vetor+i));
            }
        }


        printf("Valor %d: ", tamanho+1);
        scanf("%d", &valor);
        if (valor == 0) {
            for (int i = 0; i < tamanho; i++) {
                printf("%d ", *(vetor+i));
            }
            free(vetor);
            break;
        } 
        *(vetor+tamanho) = valor;
        cont++;
        tamanho++;
    }

    return 0;
}
