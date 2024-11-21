#include <stdio.h>

void preencherMatriz(int linhas, int colunas, int matriz[linhas][colunas]) {
  int l, c;

  for (l = 0; l < linhas; l++) {
    for (c = 0; c < colunas; c++) {
      printf("Entre com o elemento matriz[%d][%d]: ", l, c);
      scanf("%d", &matriz[l][c]);
    }
  }
}

void exibirMatriz(int linhas, int colunas, int matriz[linhas][colunas]) {
  int l, c;

  printf("Matriz completa: \n");

  for (l = 0; l < linhas; l++) {
    for (c = 0; c < colunas; c++) {
      printf("%3d ",
             matriz[l][c]); // %3d para formataÃ§Ã£o da impressÃ£o com 3 espaÃ§os
    }
    printf("\n");
  }
}

void exibirElemento(int elemento) {

  printf("Ultimo elemento: %d \n", elemento);
}

void multiplicarElemento(int *elemento) {

  *elemento = *elemento * 3;

  printf("Elemento multiplicado por 3: %d \n", *elemento);
}

int main() {

  int linhas = 2, colunas = 4;
  int matriz[linhas][colunas];

  /* ------------ preenche matriz completa ------------ */
  preencherMatriz(linhas, colunas, matriz);

  /* -------------- exibe matriz completa ------------- */
  // alteraÃ§Ãµes realizadas na funÃ§Ã£o sÃ£o feitas direto na memÃ³ria,
  // entÃ£o tem efeito na main (assim como em passagem por referÃªncia)
  exibirMatriz(linhas, colunas, matriz);

  /* --------- passagem de elemento por valor --------- */
  // -1 porque quero o Ãºltimo elemento da matriz, neste caso, matriz[2][2]
  exibirElemento(matriz[linhas - 1][colunas - 1]);

  /* ------- passagem de elemento por referÃªncia ------ */
  // lembrar de utilizar & na chamada e * na funÃ§Ã£o
  multiplicarElemento(&matriz[0][2]);

  return 0;
}