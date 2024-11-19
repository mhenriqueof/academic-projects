# include <stdio.h>
# include <stdlib.h>
# include <time.h>

int main() {

    srand(time(0));

    float empresa[3][6];

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 6; j++) {
            empresa[i][j] = (rand() % 2000 + 1000) + (rand() % 100 / 100.0);
        }
        printf("\n");
    }

    for (int i = 0; i < 3; i++) {
        float total_pago = 0;
        printf("--- Loja %d ---\n", i+1);
        for (int j = 0; j < 6; j++) {
            printf("Salario funcionario %d: %.2f\n", j+1, empresa[i][j]);
            total_pago += empresa[i][j];
        }
        printf("Total pago em salario pela loja: %.2f\n", total_pago);
    }

    printf("Funcionarios que recebem salario superior a R$ 2.000,00 na primeira loja: \n");
    
    for (int j = 0; j < 6; j++) {
        if (empresa[0][j] > 2000) {
            printf("Funcionario %d\n", j+1);
        }
    }

    float total_loja = 0;
    for (int j = 0; j < 6; j++) {
        total_loja += empresa[1][j];
    }
    printf("Media salarial da segunda loja: %.2f", total_loja / 6);

    return 0;
}
