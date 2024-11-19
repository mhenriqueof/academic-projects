# include <stdio.h>

typedef struct {
    float saldo, valores[5];
    int chaves[5];
} clientes;


float scan_saldo() {
    float saldo;
    printf("Saldo da conta: ");
    scanf("%f", &saldo);
    return saldo;
}

int main() {

    clientes cliente;
    int chave, cont = 0;
    float valor;

    cliente.saldo = scan_saldo();
    // printf("%f", cliente.saldo);
    
    for (int i = 0; i < 5; i++) {

        printf("Chave do %do envio: ", i+1);
        scanf("%d", &chave);

        printf("Valor do %do pix: ", i+1);
        scanf("%f", &valor);

        if (valor > cliente.saldo) {
            printf("Valor infusiciente.\n");
            // /0;
            break;
        } else {
            cliente.saldo -= valor;
            cliente.valores[i] = valor;
            cliente.chaves[i] = chave;
            cont++;
        }
     }

    for (int i = 0; i < cont; i++) {
        printf("%da transferencia com o valor de %.2f para o pix %d.\n", i+1, cliente.valores[i], cliente.chaves[i]);
    }
    printf("Saldo final da conta: %.2f", cliente.saldo);

    return 0;
}
