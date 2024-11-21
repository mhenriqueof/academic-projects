#include <stdio.h>

// tambÃ©m funciona com valores[]
void preenche(float *valores, int qtd) {
  for(int i = 0; i < qtd; i++) {
    printf("Digite o valor %d: ", i);
    scanf("%f", &valores[i]);
  }
}

// tambÃ©m funciona com valores[]
float calc_media(float *valores, int qtd) {

  float soma = 0;

  for(int i = 0; i < qtd; i++) {
    soma += valores[i];
  }

  return soma / qtd;
}

// passagem por valor
void imprimeElemento(float num) {
  printf("Elemento: %f\n", num);  
}

// passagem por referÃªncia
void editaElemento(float *num) {
  *num = 1000000.0;
}

int main () {

  int tamanho;

  printf("Tamanho desejado: ");
  scanf("%i", &tamanho);

  float valores[tamanho], media;

  /* ----------- passagem de vetor completo ---------- */
  // passar somente o nome do vetor
  // alteraÃ§Ãµes realizadas na funÃ§Ã£o sÃ£o feitas direto na memÃ³ria,
  // entÃ£o tem efeito na main (assim como em passagem por referÃªncia)
  preenche(valores, tamanho);

  media = calc_media(valores, tamanho);

  printf("\nMedia: %.2f\n", media);

  /* ----------- passagem de parte do vetor ---------- */
  // passar o nome do vetor e o Ã­ndice desejado
  // passar por valor ou por referÃªncia, dependendo do que Ã© 
  // feito na funÃ§Ã£o

  // passagem de parÃ¢metro por valor
  imprimeElemento(valores[3]);

  // passagem de parÃ¢metro por referÃªncia
  editaElemento(&valores[3]);

  imprimeElemento(valores[3]);

  return 0;
}