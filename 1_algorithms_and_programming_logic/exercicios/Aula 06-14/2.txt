#include <stdio.h>
# include <string.h>

typedef struct {
    char nome[20];
    float renda;
    float idh;
    float populacao;
} cidades;

int main() {

    int tamanho;
    printf("Numero cidades: ");
    scanf("%d", &tamanho);
    cidades cidade[tamanho];
    
    float soma, maior_pop = 0;
    char city[20];
    
    for (int i = 0; i < tamanho; i++) {
        
        printf("--- Cidade %d ---\n", i+1);
        
        fflush(stdin);
        printf("Nome: ");
        scanf("%s", cidade[i].nome);
        
        printf("Renda per capita: ");
        scanf("%f", &cidade[i].renda);
        
        printf("IDH: ");
        scanf("%f", &cidade[i].idh);
        
        printf("Populacao: ");
        scanf("%f", &cidade[i].populacao);
        
        soma += cidade[i].renda;
    }
    
    printf("Media renda: %.2f\n", soma / tamanho);

    for (int i = 0; i < tamanho; i++) {
        if (cidade[i].populacao > maior_pop) {
            maior_pop = cidade[i].populacao;
        }
    }
    
    printf("Cidade com a maior populacao (%.2f):\n", maior_pop);
    for (int i = 0; i < tamanho; i++) {
        if (cidade[i].populacao == maior_pop) {
            printf("%s\n", cidade[i].nome);
        }
    }
    
    fflush(stdin);
    printf("Pesquisar cidade: ");
    scanf("%s", city);
    
    for (int i = 0; i < tamanho; i++) {
        int ret = strcmp(city, cidade[i].nome);
        if (ret == 0) {
            printf("%.2f\n", cidade[i].renda);
            printf("%.2f\n", cidade[i].idh);
            printf("%.2f\n", cidade[i].populacao);
        }
    }
    
    return 0;
}
