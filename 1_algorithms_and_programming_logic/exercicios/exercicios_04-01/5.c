// (Beecrowd | 2780) A organização da OIBR, OlimpíadaInternacional de Basquete de Robô, está começando a ter problemas. É que osrobôs desses times acertam quase todos os lançamentos, de qualquer posiçãona quadra! Pensando bem, o jogo de basquete ficaria mesmo sem graça sejogadores conseguissem acertar qualquer lançamento, não é mesmo? Umadas medidas que a OIBR está implantando é uma nova pontuação para oslançamentos, de acordo com a distância do robô para o início da quadra.A quadra tem 2000 centímetros de comprimento. Dada a distância D dorobô até o início da quadra, onde está a cesta, a regra é a seguinte:● Se 0 ≤ D ≤ 800, a cesta vale 1 ponto;● Se 800 < D ≤ 1400, a cesta vale 2 pontos;● Se 1400 < D ≤ 2000, a cesta vale 3 pontos.A organização da OIBR precisa de ajuda para automatizar o placar dojogo. Dado o valor da distância D (que não deve ser negativa e nem maior que os 2000 centímetros do tamanho da quadra), você deve escrever um programapara calcular o número de pontos do lançamento

#include <stdio.h>

int main() {
    
    int distancia, ponto;
    
    printf("Distância: ");
    scanf("%d", &distancia);
    
    if (distancia > 2000 || distancia < 0) {
        printf("Valor inválido.");
        return 1;
    } else if (distancia > 1400) {
        ponto = 3;
    } else if (distancia > 800) {
        ponto = 2;
    } else {
        ponto = 1;
    }
    
    printf("Ponto: %d", ponto);

    return 0;
}
