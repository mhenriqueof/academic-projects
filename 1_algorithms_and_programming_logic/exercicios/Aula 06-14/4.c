# include <stdio.h>

typedef struct {
    int num;
    char nome[20];
    float espaco;
} usuarios;

int main() {

    float total = 0;
    int tamanho = 6;
    usuarios usuario[tamanho];

    for (int i = 0; i < tamanho; i++) {
        printf("--- Usuario %d ---\n", i);

        usuario[i].num = i;

        fflush(stdin);
        printf("Nome: ");
        scanf("%[^\n]s", usuario[i].nome);

        printf("Espaco: ");
        scanf("%f", &usuario[i].espaco);
        total += usuario[i].espaco;
    }

    printf("Nr.      Usuario        Espaco utilizado           %% de uso\n");
    printf("------------------------------------------------------------\n");
    for (int i = 0; i < tamanho; i++) {
        printf("%d       %s               %.2fMB                 %.2f\n", usuario[i].num, usuario[i].nome, usuario[i].espaco, (usuario[i].espaco * 100) / total);
    }
    printf("Espaco total: %.2fMB\n", total);
    printf("Espaco medio: %.2fMB\n", total / tamanho);

    return 0;
}
