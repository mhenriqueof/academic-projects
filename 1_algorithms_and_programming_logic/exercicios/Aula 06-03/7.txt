# include <stdio.h>
# include <stdlib.h>
# include <time.h>

void gerar_senha(int comprimento, int opcao, char *senha) {

    int cont = 0;

    if (opcao == 0) { 
        for (int i = 0; i < comprimento; i++) {
            int random = rand() % 3;
            if (cont < 4) {
                random = cont;
            }
            if (random == 0) {
                senha[i] = rand() % 10 + 48;
            } else if (random == 1) {
                senha[i] = rand() % 26 + 65;
            } else if (random == 2) {
                senha[i] = rand() % 26 + 97;
            }
        cont++;
        }
    } else {
        for (int i = 0; i < comprimento; i++) {
            int random = rand() % 4, caracteres_random = rand() % 7;
            if (cont < 4) {
                random = cont;
            }
            if (random == 0) {
                senha[i] = rand() % 10 + 48;
            } else if (random == 1) {
                senha[i] = rand() % 26 + 65;
            } else if (random == 2) {
                senha[i] = rand() % 26 + 97;
            } else if (random == 3) {
                char caracteres[7] = "!@#$%&?";
                senha[i] = caracteres[caracteres_random];
            }
        cont++;
        }
    }
}

int main() {

    int comprimento, carac_especiais = 0;
    
    srand(time(0));

    printf("Comprimento da senha: ");
    scanf("%d", &comprimento);

    printf("Usar caracteres especiais? [0] NAO | [1] SIM ");
    scanf("%d", &carac_especiais);

    char senha[comprimento];
    gerar_senha(comprimento, carac_especiais, senha);

    for (int i = 0; i < comprimento; i++) {
        printf("%c", senha[i]);
    }

    return 0;
}
