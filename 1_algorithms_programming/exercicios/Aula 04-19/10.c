// Crie um algoritmo que ajude o DETRAN a saber o total derecursos que foram arrecadados com a aplicação de multas de trânsito. Oalgoritmo deve ler as seguintes informações para cada motorista:● O número da carteira de motorista (de 1 a 4327)● Número de multas;● Valor da cada uma das multas.Deve ser impresso o valor da dívida de cada motorista e, ao final daleitura, o total de recursos arrecadados (somatório de todas as multas). Oalgoritmo deverá imprimir também o número da carteira do motorista queobteve o maior número de multas

#include <stdio.h>

int main() {
    
    int n_carteira = 1, n_multas = 0, maior_multas, motorista_maior;
    float multas_total = 0;
    
    while (1) {
        
        float valor_multa = 0, valor_multas = 0;
        
        printf("Numero da carteira: ");
        scanf("%d", &n_carteira);
        
        if (n_carteira > 4327 || n_carteira < 1) {
            break;
        }
        
        printf("Numero de multas: ");
        scanf("%d", &n_multas);
        
        if (n_multas > maior_multas) {
            maior_multas = n_multas;
            motorista_maior = n_carteira;
        }
        
        for (int i = 1; i <= n_multas; i++) {
            printf("Valor da multa %d: ", i);
            scanf("%f", &valor_multa);
            valor_multas += valor_multa;
        }
        printf("Valor da divida do motorista %d: %.2f\n", n_carteira, valor_multas);
        printf("---\n");
        multas_total += valor_multas;
    }
    
    printf("Somatorio de todas as multas: %.2f\n", multas_total);
    printf("O motorista %d teve o maior numero de multas: %d", motorista_maior, maior_multas);

    return 0;
}
