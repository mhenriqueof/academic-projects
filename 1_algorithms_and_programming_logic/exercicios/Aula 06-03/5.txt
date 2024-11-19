# include <stdio.h>

int qtd_pessoas(int *adultos, int *criancas) {
    
    printf("Quantidade de adultos: ");
    scanf("%d", &*adultos);

    printf("Quantidade de criancas: ");
    scanf("%d", &*criancas);

    return *adultos + *criancas;
}

void qtd_itens(float *kg, float *litros, int adultos, int criancas) {
    
    *kg = ((250 * adultos)/1000.0) + ((125 * criancas)/1000.0);
    printf("\nSera necessario %.2f KG de carne.\n", *kg);

    *litros = (700 * adultos)/1000.0 + (350 * criancas)/1000.0;
    printf("Sera necessario %.2f litros de bebidas.\n\n", *litros);
}

float calcular_total(float kg, float litros) {
    
    float valor_carne = 10 * kg;
    float valor_bebidas = 5 * litros;

    return valor_carne + valor_bebidas;
}

int main() {

    int adultos = 0, criancas = 0, pessoas;
    float kg_carne, litros_bebidas, total_pagar;

    printf("\nCarne = R$ 10/KG\nBebidas = R$ 5/Litro\n\n");

    pessoas = qtd_pessoas(&adultos, &criancas);
    qtd_itens(&kg_carne, &litros_bebidas, adultos, criancas);
    total_pagar = calcular_total(kg_carne, litros_bebidas);    

    printf("Total: R$ %.2f\nCada uma das %d pessoas terao que pagar: R$ %.2f", total_pagar, pessoas, total_pagar/pessoas);

    return 0;
}
