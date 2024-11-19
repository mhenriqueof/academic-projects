# include <stdio.h>

int menu() {

    int valor;
    printf("--- Menu ---\n");
    printf("\
[1] Depositar\n\
[2] Sacar\n\
[3] Saldo\n\
[0] Sair\n");
    scanf("%d", &valor);
    
    return valor;
}

void depositar(float *saldo) {
    float valor;
    printf("Depositar valor: ");
    scanf("%f", &valor);
    *saldo += valor;
}

void sacar(float *saldo) {
    float valor;
    printf("Sacar valor: ");
    scanf("%f", &valor);

    if (valor > *saldo) {
        printf("Valor invalido para o seu saldo.\n");
    } else {
        *saldo -= valor;
    }
}

void balance(float saldo) {
    printf("Saldo: %.2f\n", saldo);
}


int main() {

    int opcao, flag = 1;
    float saldo = 1000;
    
    while (flag) {
        opcao = menu();

        switch (opcao) {
            case 0:
                flag = 0;
                break;
            case 1:
                depositar(&saldo);
                break;
            case 2:
                sacar(&saldo);
                break;
            case 3:
                balance(saldo);
                break;
        }
    }
    
    return 0;
}
