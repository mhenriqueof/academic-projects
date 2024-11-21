#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  int numero_aleatorio;

  srand(time(NULL));               // semente da funÃ§Ã£o rand
  numero_aleatorio = rand() % 101; // gerar valores de 0 a 100

  printf("Valor: %d", numero_aleatorio);

  return 0;
}