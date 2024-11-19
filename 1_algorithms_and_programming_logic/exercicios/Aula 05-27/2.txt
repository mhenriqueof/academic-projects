# include <stdio.h>

int scan_number() {

    int number;
    printf("Digite o numero correspondente ao mes do ano: ");
    scanf("%d", &number);
    
    return number;
}

void mes(int numero_mes){
    if (numero_mes > 12 || numero_mes < 1) {
        printf("Valor invalido.");
    } else if (numero_mes == 1) {
        printf("Janeiro");
    } else if (numero_mes == 2) {
        printf("Fevereiro");
    } else if (numero_mes == 3) {
        printf("Marco");
    } else if (numero_mes == 4) {
        printf("Abril");
    } else if (numero_mes == 5) {
        printf("Maio");
    } else if (numero_mes == 6) {
        printf("Junho");
    } else if (numero_mes == 7) {
        printf("Julho");
    } else if (numero_mes == 8) {
        printf("Agosto");
    } else if (numero_mes == 9) {
        printf("Setembro");
    } else if (numero_mes == 10) {
        printf("Outubro");
    } else if (numero_mes == 11) {
        printf("Novembro");
    } else if (numero_mes == 12) {
        printf("Dezembro");
    }
}

int main() {
    
    int numero = scan_number();

    mes(numero);

    return 0;
}
