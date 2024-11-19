// Sabe-se que, para iluminar de maneira correta os cômodos de uma casa,para cada m² deve-se usar 18W de potência. Faça um programa que recebe as duasdimensões de um cômodo (em metros), calcule e mostre a sua área (em m²) e a potênciade iluminação em watts que deverá ser usada.

# include <stdio.h>
# include <math.h>

# define POTENCIA 18

int main() {
    
    float largura, comprimento, area;
    
    printf("Largura: ");
    scanf("%f", &comprimento);
    
    printf("Comprimento: ");
    scanf("%f", &largura);
    
    area = largura * comprimento;
    
    printf("Área de %.2f m^2 e a potência de %.0f watts.", area, ceil(area * POTENCIA));
    
    return 0;
}
