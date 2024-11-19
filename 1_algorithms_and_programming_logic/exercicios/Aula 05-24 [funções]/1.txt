#include <stdio.h>

double getvalue() {
    
    double num;
    
    do{
        printf("Digite um valor inteiro: ");
        scanf("%f", &num);
    } while (num <= 0);
    
    printf("\n%f\n", num);
    
    return num;
}

void potencia(double x, double y) {
    
    double resultado = x;

    for (int i = 1; i <= y; i++) {
        resultado *= resultado;
    }
    
    printf("\n%.2f", resultado);
}

int main() {
    
    double x = getvalue();
    double y = getvalue();
    
    potencia(x, y);
    return 0;
}