// Escreva um algoritmo que calcule e apresente na tela o resultado de C = ( A+ B ) x B.

#include <stdio.h>

int main() {
   
   float a, b, c;
   
   printf("A: ");
   scanf("%f", &a);
   
   printf("B: ");
   scanf("%f", &b);
   
   c = (a + b) * b;
   
   printf("%.2f", c);
   
   return 0;
}
