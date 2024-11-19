/* Uma empresa possui três lojas, cada uma com 6 funcionários. Escreva um programa que forneça à
gerência algumas informações relativas aos salários dos funcionários dessa empresa. Os salários
devem ser armazenados em uma matriz bidimensional (loja X funcionário). O programa deve:
a. preencher a matriz de salários por leitura do teclado;
b. imprimir os salários de todos os funcionários, identificando qual a loja em que trabalha;
c. imprimir o total pago em salários por loja;
d. informar quantos funcionários recebem salário superior a R$ 2.000,00 na primeira loja;
e. informar a média salarial da segunda loja.
EDELWEISS, Nina. Algoritmos e programação com exemplos em Pascal e C. Porto Alegre Bookman 2014 1 recurso on-line (Livros didáticos UFRGS 23). */

# include <stdio.h>

int main() {
    
    float matriz[3][6], salario, pagos[3] = {0, 0, 0}, soma = 0;
    int sup_cont = 0;
    
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 6; j++) {
            
            printf("Salario do funcionario %d da loja %d: ", j+1, i+1);
            scanf("%f", &salario);
            
            matriz[i][j] = salario;
        }
    }
    
    printf("---\n");
    
    for (int i = 0; i < 3; i++) {
        
        printf("Loja %d\n", i+1);
        
        for (int j = 0; j < 6; j++) {
            printf("Salario do funcionario %d: %.2f\n", j+1, matriz[i][j]);
                pagos[i] += matriz[i][j];
        }
        printf("\n");
    }
    
    printf("---\n");
    
    for (int i = 0; i < 3; i++) {
        
        printf("Total a pagar da loja %d: %f\n", i+1, pagos[i]);
    }
    
    printf("---\n");
    
    for (int i = 0; i < 6; i++) {
        if (matriz[0][i] > 2000) {
            sup_cont += 1;
        }
    }
    
    printf("Maiores que 2000 na loja 1: %d\n", sup_cont);
    
    for (int i = 0; i < 6; i++) {
        soma += matriz[1][i];
    }
    
    printf("---\n");
    
    printf("Media salarial da loja 2: %.2f", soma / 6);
    
    return 0;
}
