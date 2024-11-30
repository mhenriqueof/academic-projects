# include <stdio.h>
# include <stdlib.h>

typedef struct {
    int id;
    char nome[50];
    int qtd;
    float preco;
} produtos;

int main() {

    int n_produtos, maior_preco_produto = 0, maior_qtd_produto = 0;
    printf("Quantidade produtos: ");
    scanf("%d", &n_produtos);

    produtos *produto = (produtos *) malloc(n_produtos * sizeof(produtos));
    if (produto == NULL) {
        return 1;
    }

    for (int i = 0; i < n_produtos; i++) {
        printf("--- Produto %d ---\n", i+1);

        scanf("%d", &(produto+i)->id);

        fflush(stdin);
        gets((produto+i)->nome);

        scanf("%d", &(produto+i)->qtd);

        scanf("%f", &(produto+i)->preco);
    }

    float maior_preco = (produto+0)->preco;
    float maior_qtd = (produto+0)->qtd;

    for (int i = 0; i < n_produtos; i++) {
        
        if (((produto+i)->preco) > maior_preco) {
            maior_preco = (produto+i)->preco;
            maior_preco_produto = i;
        }

        if (((produto+i)->qtd) > maior_qtd) {
            maior_qtd = (produto+i)->qtd;
            maior_qtd_produto = i;
        }
    }

    printf("Produto com maior preco: %s (%.2f)\n", (produto+maior_preco_produto)->nome, maior_preco);
    printf("Produto com maior quantidade: %s (%.2f)\n", (produto+maior_qtd_produto)->nome, maior_qtd);

    free(produto);

    return 0;
}
