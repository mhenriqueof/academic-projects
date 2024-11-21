# include <stdio.h>
# include <string.h>
# include <ctype.h>

typedef struct {
    char placa[8];
    int hora_entrada;
    int minutos_entrada;
} veiculos;

void menu() {
    printf("# Estacionamento do Chaves #\n\
[1] Entrada de veiculo\n\
[2] Saida de veiculo\n\
[3] Listagem de veiculos\n\
[4] Sair\n");
}

void entrada_veiculo(int *numero_veiculos, veiculos *veiculo) {

    if (*numero_veiculos > 10) {
        printf("Estacionamento lotado!\n");
    } else {

        char placa[8]; 
        fflush(stdin);
        printf("Informe a placa: ");
        scanf("%[^\n]s", placa);
        if (strlen(placa) != 8) {
            printf("Valor invalido.\n");
        } else {
            for (int i = 0; i < (int)strlen(placa); i++) {
                veiculo[*numero_veiculos].placa[i] = toupper(placa[i]);
            }

            char horario[5];
            fflush(stdin);
            printf("Informe o horario de entrada: ");
            scanf("%[^\n]s", horario);
            if (strlen(horario) != 5) {
                printf("Valor invalido.\n");
            } else {
                veiculo[*numero_veiculos].hora_entrada = (horario[0] - '0') * 10 + (horario[1] - '0');
                veiculo[*numero_veiculos].minutos_entrada = (horario[3] - '0') * 10 + (horario[4] - '0');

                *numero_veiculos = *numero_veiculos + 1;
                printf("Veiculo cadastrado com sucesso!\n");
            }
        }
    }
}

void saida_veiculo(int *numero_veiculos, veiculos *veiculo) {
   
        char placa[8]; 
        fflush(stdin);
        printf("Informe a placa: ");
        scanf("%[^\n]s", placa);
        if (strlen(placa) != 8) {
            printf("Valor invalido.\n");
        } else {
            for (int i = 0; i < (int)strlen(placa); i++) {
                placa[i] = toupper(placa[i]);
                // printf("%c", placa[i]);
            }
            // printf("\n");
            int cont = 0, pos_veiculo = -1;
            for (int i = 0; i < *numero_veiculos; i++) {
                for (int j = 0; j < 8; j++) {
                    if (placa[j] == veiculo[i].placa[j]) {
                        cont++;
                        // printf("\n%d ", cont);
                    }
                    // printf("\n");
                }
                if (cont >= 8) {
                    pos_veiculo = i;
                    cont = 0;
                    break;
                }
            }

            if (pos_veiculo == -1) {
                printf("Veiculo nao encontrado.\n");
            } else {
                char horario[5];
                int hora_saida, minuto_saida, minutos_total, multi;
                float total_pagar = 5;
                fflush(stdin);
                printf("Informe o horario de saida: ");
                scanf("%[^\n]s", horario);
                if (strlen(horario) != 5) {
                    printf("Valor invalido.\n");
                } else {
                    hora_saida = (horario[0] - '0') * 10 + (horario[1] - '0');
                    minuto_saida = (horario[3] - '0') * 10 + (horario[4] - '0');

                    minutos_total = ((hora_saida * 60) + minuto_saida) - ((veiculo[pos_veiculo].hora_entrada * 60) + veiculo[pos_veiculo].minutos_entrada);
                    // printf("%d", minutos_total);

                    printf("-----------------------------\n");
                    printf("[Recibo]\n");
                    printf("Placa: ");
                    for (int i = 0; i < 8; i++) {
                        printf("%c", veiculo[pos_veiculo].placa[i]);
                    };
                    printf("\nEntrada: %02d:%02d\n", veiculo[pos_veiculo].hora_entrada, veiculo[pos_veiculo].minutos_entrada);
                    printf("Saida: %02d:%02d\n", hora_saida, minuto_saida);
                    printf("Tempo total: %d minutos\n", minutos_total);
                    printf("Total a pagar: R$ ");
                    if (minutos_total < 60) {
                        printf("%.2f\n", total_pagar);
                    } else {
                        minutos_total -= 60;
                        multi = minutos_total / 15;
                        total_pagar += 2 * multi;
                        printf("%.2f\n", total_pagar);
                    }

                    *numero_veiculos = *numero_veiculos - 1;
                    for (int i = 0; i < *numero_veiculos; i++) {
                            veiculo[pos_veiculo+i] = veiculo[pos_veiculo+1+i];
                    }
                }
            }
        }
}

void listagem_veiculos(int numero_veiculos, veiculos *veiculo) {
    printf("Nr. vaga        Placa         Entrada\n");

    for (int i = 0; i < numero_veiculos; i++) {
        printf("%d              ", i+1);
        for (int j = 0; j < 8; j++) {
            printf("%c", veiculo[i].placa[j]);
        }
        printf("         %02d:%02d\n", veiculo[i].hora_entrada, veiculo[i].minutos_entrada);
    }
}


int main() {

    veiculos veiculo[10];
    int numero_veiculos = 0, opcao;

    while (1) {
        
        menu();
        scanf("%d", &opcao);
        printf("-----------------------------\n");
        if (opcao == 4) {
            return 1;
        } else if (opcao == 1) {
            entrada_veiculo(&numero_veiculos, veiculo);
        } else if (opcao == 2) {
            saida_veiculo(&numero_veiculos, veiculo);
        } else if (opcao == 3) {
            listagem_veiculos(numero_veiculos, veiculo);
        } else {
            printf("Opcao invalida.\n");
        }
        printf("Vagas disponiveis: %d\n", 10 - numero_veiculos);
        printf("-----------------------------\n");
    }
    
    return 0;
}
