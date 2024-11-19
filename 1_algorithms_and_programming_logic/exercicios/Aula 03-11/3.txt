// Elabore um algoritmo que leia o valor do salário mínimo e o valor do salário de umapessoa digitados pelo usuário. Calcular e imprimir quantos salários mínimos essapessoa ganha

#include <stdio.h>

int main() {
    
    const float SALARIO_MIN = 1412;
    float salario_usu;
    
    printf("Salário do usuário: ");
    scanf("%f", &salario_usu);
    
    printf("\nEssa pessoa ganha %.1f salários mínimo.", salario_usu / SALARIO_MIN);
    
}
