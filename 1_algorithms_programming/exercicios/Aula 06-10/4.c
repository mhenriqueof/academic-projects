# include <stdio.h>

typedef struct {
    char nome[50];
    float altura;
} pessoas;

int main() {

    int tamanho = 5;
    float soma = 0;
    pessoas pessoa[tamanho];

    for (int i = 0; i < tamanho; i++) {

        printf("-- Pessoa %d ---\n", i+1);

        fflush(stdin);
        printf("Nome: ");
        scanf("%s", pessoa[i].nome);

        printf("Altura: ");
        scanf("%f", &pessoa[i].altura);

        soma += pessoa[i].altura;
    }

    printf("--- Pessoas 1.50 ou menos ---\n");
    for (int i = 0; i < tamanho; i++) {
        if (pessoa[i].altura <= 1.5) {   
            printf("Nome: %s | Altura: %.2f\n", pessoa[i].nome, pessoa[i].altura);
        } 
    }
    printf("\n");
    
    printf("--- Pessoas mais de 1.50 ---\n");
    for (int i = 0; i < tamanho; i++) {
        if (pessoa[i].altura > 1.5) {
            printf("Nome: %s | Altura: %.2f\n", pessoa[i].nome, pessoa[i].altura);
        }
    }
    printf("\n");

    printf("--- Pessoas entre 1.50 e 1.8 ---\n");
    for (int i = 0; i < tamanho; i++) {
        if (pessoa[i].altura > 1.5 && pessoa[i].altura < 1.8) {
            printf("Nome: %s | Altura: %.2f\n", pessoa[i].nome, pessoa[i].altura);
        }
    }
    printf("\n");

    printf("--- Pessoas acima da media [%.2fm] ---\n", soma / tamanho);
    for (int i = 0; i < tamanho; i++) {
        if (pessoa[i].altura >= soma / tamanho) {
            printf("Nome: %s | Altura: %.2f\n", pessoa[i].nome, pessoa[i].altura);
        }
    }
    printf("\n");

    return 0;
}
