#include <stdio.h>

typedef struct {
    char nome[50];
    float peso;
    float altura;
    float imc;
} esportistas;

int main() {
    
    int tamanho = 2;
    esportistas esportista[tamanho];
    
    for (int i = 0; i < tamanho; i++) {
        
        fflush(stdin);
        printf("Nome esportista %d: ", i+1);
        scanf("%s", esportista[i].nome);
        
        printf("Peso esportista %d: ", i+1);
        scanf("%f", &esportista[i].peso);
        
        printf("Altura esportista %d: ", i+1);
        scanf("%f", &esportista[i].altura);
        
        esportista[i].imc = esportista[i].peso / (esportista[i].altura * esportista[i].altura);
    }
    
    for (int i = 0; i < tamanho; i++) {
        printf("%s\n", esportista[i].nome);
        printf("%f\n", esportista[i].peso);
        printf("%f\n", esportista[i].altura);
        printf("%f\n\n", esportista[i].imc);
    }

    return 0;
}