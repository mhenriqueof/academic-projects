# include <stdio.h>
# include <stdlib.h>

typedef struct {
    char nome[50];
    char data_nascimento[11];
    int cpf;
 } pessoas;

void preencher(pessoas *pessoa) {

    fflush(stdin);
    printf("Nome: ");
    gets(pessoa->nome);

    fflush(stdin);
    printf("Data nascimento: ");
    gets(pessoa->data_nascimento);

    printf("CPF: ");
    scanf("%d", &pessoa->cpf);
}

void mostrar(pessoas *pessoa) {
    printf("\n");

    printf("--- Dados de %s ---\n", pessoa->nome);
    printf("Data de nascimento: %s\n", pessoa->data_nascimento);
    printf("CPF: %d\n", pessoa->cpf);
}

int main() {

    pessoas *pessoa = (pessoas *) malloc(1 * sizeof(pessoas));

    preencher(pessoa);

    mostrar(pessoa);

    return 0;
}
