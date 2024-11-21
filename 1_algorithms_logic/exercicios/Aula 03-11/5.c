// Leia 3 valores, no caso, variáveis A, B e C, que são as três notas de um aluno. Aseguir, calcule a média do aluno, sabendo que a nota A tem peso 2, a nota B tempeso 3 e a nota C tem peso 5.

#include <stdio.h>

int main() {
    
    float a, b, c, media_ponderada;
    
    printf("Nota A: ");
    scanf("%f", &a);
    printf("Nota B: ");
    scanf("%f", &b);
    printf("Nota C: ");
    scanf("%f", &c);
    
    media_ponderada = ((a * 2) + (b * 3) + (c * 5)) / 10;
    
    printf("%.2f", media_ponderada);
    
}
