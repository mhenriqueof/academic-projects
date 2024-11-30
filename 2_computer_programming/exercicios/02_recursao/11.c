#include <stdio.h>

#define MAX_DEZENAS 60
#define TAM_COMBINACAO 6

void gerarCombinacoes(int inicio, int profundidade, int combinacao[], int tamanho) {
    // Caso base: quando a combinação atingir o tamanho desejado
    if (profundidade == TAM_COMBINACAO) {
        for (int i = 0; i < TAM_COMBINACAO; i++) {
            printf("%d ", combinacao[i]);
        }
        printf("\n");
        return;
    }

    // Gerar combinações recursivamente
    for (int i = inicio; i <= MAX_DEZENAS - (TAM_COMBINACAO - profundidade) + 1; i++) {
        combinacao[profundidade] = i; // Adiciona o número atual na combinação
        gerarCombinacoes(i + 1, profundidade + 1, combinacao, tamanho); // Próxima chamada recursiva
    }
}

int main() {
    int combinacao[TAM_COMBINACAO]; // Armazena a combinação atual
    gerarCombinacoes(1, 0, combinacao, TAM_COMBINACAO);
    return 0;
}
