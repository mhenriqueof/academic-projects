// Escreva um programa que leia o nome de um funcionário, seu número de horastrabalhadas, o valor que recebe por hora e calcule o salário desse funcionário. Aseguir, mostre o nome e o salário do funcionário.

#include <stdio.h>

int main() {
    
    char nome[50];
    float horas, salario_hora, salario;
    
    printf("Digite o nome: ");
    scanf("%s", nome);
    
    printf("Número de horas trabalhadas: ");
    scanf("%f", &horas);
    
    printf("Valor por hora de trabalho: ");
    scanf("%f", &salario_hora);
    
    salario = salario_hora * horas;
    
    printf("O salário de %s é %f", nome, salario);
    
}
