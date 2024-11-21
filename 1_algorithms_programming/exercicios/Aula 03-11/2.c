// Elabore um algoritmo que leia uma temperatura em graus Celsius digitada pelousuário e apresente-a convertida em graus Fahrenheit. A fórmula de conversão é:F = (9.0/5.0) * C + 32.0,em que F é a temperatura em Fahrenheit e C é a temperatura em Celsius.
#include <stdio.h>

int main() {
    
    float celsius;
    float fahren;
    
    printf("Número em Celsius: ");
    scanf("%f", &celsius);
    
    fahren = ((celsius / 5) * 9) + 32;
    
    printf("Valor em Fahren: %.1f", fahren);
}