// Faça um programa em para calcular e imprimir o valor do volume de uma latade óleo, utilizando a fórmula

# include <stdio.h>
# include <math.h>

# define PI 3.1415

int main() {

    float volume, raio, altura;
    
    printf("Raio: ");
    scanf("%f", &raio);
    
    printf("Altura: ");
    scanf("%f", &altura);
    
    volume = PI * pow(raio, 2) * altura;
    
    printf("%.2f", volume);
    
    return 0;
}
