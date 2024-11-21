// Escreva um algoritmo para validar um lote de recibos bancários.O programa deverá inicialmente solicitar o valor (soma) total do lote e onúmero de recibos. A seguir deverá ler o valor de cada recibo calculando ovalor (soma) total. Após a digitação dos valores de todos os recibos, oprograma deverá imprimir as seguintes mensagens: “LOTE Ok” se a soma
// informada for igual a soma calculada; “Diferença negativa” se a soma calculadafor menor que a informada; e “Diferença positiva” se a soma calculada formaior que a informada. Observação: O valor da diferença deve ser impresso(caso exista).

#include <stdio.h>

int main() {
    
    int numero_recibos;
    float valor_total, valor, soma, diferenca;
    
    printf("Valor total: ");
    scanf("%f", &valor_total);
    
    printf("Numero de recibos: ");
    scanf("%d", &numero_recibos);
    
    for (int i = 1; i <= numero_recibos; i++) {
        printf("Valor do recibo %d: ", i);
        scanf("%f", &valor);
        
        soma += valor;
    }
    
    diferenca = valor_total - soma;
    if (diferenca != 0) {
        if (diferenca < 0) {
            diferenca *= -1;
        }
        printf("Diferenca de %.2f\n", diferenca);
    }

    if (diferenca == 0) {
        printf("LOTE Ok");
    } else if (diferenca > 0) {
        printf("Diferenca negativa");
    } else {
        printf("Diferenca positiva");
    }
    
    return 0;
}
