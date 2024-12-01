# include <stdio.h>
# include <string.h>
# include <unistd.h>

// Funcoes
void linha() {
    printf("--------------------------------------------------\n");
}

void menu_inicial() {
    printf("- Mini Emulador MIPS\n");
    printf("-- Operacoes disponiveis\n");
    printf("--- Aritmeticas: add, sub, mul, div, addi\n");
    printf("--- Imediatas: la, li\n");
    printf("--- Salto: j, jr, jal\n");
    printf("-- Regras\n");
    printf("--- Utilizar apenas letras minusculas\n");
    printf("--- Utilizar apenas numeros inteiros e com ate 3 digitos\n");
    printf("--- Utilizar somente 3 registradores do tipo saved [s0, s1, s2]\n");
    printf("--- Utilizar um determinado registrador somente uma vez em uma instrucao\n");
    printf("-- O simulador e limitado a ter apenas 20 instrucoes\n");
    sleep(1);
    for (int i = 3; i > 0; i--) {
        printf("%d\n", i);
        sleep(1);
    }
    linha();
} 

void mostrar_interface_pc_instrucoes_registradores(int s0, int s1, int s2, int pc, char instrucoes[][30]) {
    printf(".data\n");
    printf("var: .word 5\n");
    printf("\n");
    printf(".text\n");
    printf("main:\n");
    int tamanho_instrucoes = pc / 4;
    for (int i = 0; i < tamanho_instrucoes; i++) {
        printf("    %02d - %s\n", 4*i, instrucoes[i+1]);
    }
    printf("\n");
    printf("s0: %d\n", s0);
    printf("s1: %d\n", s1);
    printf("s2: %d\n", s2);
    linha();
}

void pegar_instrucao(char instrucao[], int pc) {
    printf("PC: %d - Instrucao: ", pc);
    fflush(stdin);
    gets(instrucao);
}

void atualizar_pc_log(int *pc, char log_instrucoes[][30], char instrucao[]) {
    *pc += 4;
    int posicao_log = *pc / 4;
    strcpy(log_instrucoes[posicao_log], instrucao);
}

void instrucao_invalida() {
    printf("Instrucao invalida.\n");
    sleep(1.5);
    linha();
};


// Verificar instrucao
int verificar_quantidade_partes();
int verificar_parte_inicial();
int verificar_parte_restante();
int verificar_inicio_do_label_e_fim_ser_numero();
int verificar_instrucao(char instrucao[], int *quantidade_partes) {
    *quantidade_partes = verificar_quantidade_partes(instrucao);
    if (*quantidade_partes == 0) {return 0;}

    int parte_inicial = verificar_parte_inicial(instrucao);
    if (parte_inicial != *quantidade_partes) {return 0;}

    int parte_restante = verificar_parte_restante(instrucao, *quantidade_partes);
    if (parte_restante != *quantidade_partes) {return 0;}

    int inicio_do_label_e_fim_ser_numero = verificar_inicio_do_label_e_fim_ser_numero(instrucao, *quantidade_partes);
    if (inicio_do_label_e_fim_ser_numero != *quantidade_partes) {return 0;}

    return 1;
}

int verificar_quantidade_partes(char instrucao[]) {
    char copia_instrucao[50];
    strcpy(copia_instrucao, instrucao);

    char *token = strtok(copia_instrucao, " ");

    int cont = 0;
    while (token != NULL) {
        token = strtok(NULL, " ");
        cont++;
        if (cont > 4) {
            return 0;
        }
    } 
    if (cont == 1) {return 0;}
    return cont;
}

int instrucao_2_partes();
int instrucao_3_partes();
int instrucao_4_partes();
int verificar_parte_inicial(char instrucao[]) {
    char copia_instrucao[50];
    strcpy(copia_instrucao, instrucao);

    char *operacao = strtok(copia_instrucao, " ");

    if (instrucao_2_partes(operacao)) {
        return 2;
    } else if (instrucao_3_partes(operacao)) {
        return 3;
    } else if (instrucao_4_partes(operacao)) {
        return 4;
    } else {
        return 0;
    }
} int instrucao_2_partes(char operacao[]) {
    return strcmp(operacao, "j") == 0 || strcmp(operacao, "jr") == 0 || strcmp(operacao, "jal") == 0;
} int instrucao_3_partes(char operacao[]) {
    return strcmp(operacao, "la") == 0 || strcmp(operacao, "li") == 0;
} int instrucao_4_partes(char operacao[]) {
    return strcmp(operacao, "add") == 0 || strcmp(operacao, "addi") == 0 || strcmp(operacao, "sub") == 0 || strcmp(operacao, "mul") == 0 || strcmp(operacao, "div") == 0;
}

int verificar_parte_Ssx();
int verificar_parte_restante(char instrucao[], int quantidade_partes) {
    if (quantidade_partes == 2) {
        return 2;
    }

    int cont = 1;

    char copia_instrucao[50];
    strcpy(copia_instrucao, instrucao);

    char *token = strtok(copia_instrucao, " ");

    if (strcmp(token, "addi") == 0) {
        token = strtok(NULL, " ");
        quantidade_partes -= 1;
        cont++;
    }

    for (int i = 1; i < quantidade_partes; i++) {
        token = strtok(NULL, " ");
        if (verificar_parte_Ssx(token, i)) {
            cont++;
        }
    }
    if (quantidade_partes == 3) {return cont+1;}
    return cont;
} int verificar_parte_Ssx(char token[], int i) {
    int tamanho = strlen(token);
    if (tamanho != 3 && tamanho != 4) {
        return 0;
    } if (i == 1 && tamanho != 4) {
        return 0;
    } if (i == 2 && tamanho != 4) {
        return 0;
    } if (i == 3 && tamanho == 4) {
        return 0;
    } if (token[0] != '$' || token[1] != 's') {
        return 0;
    } if (token[2] < 48 || token[2] > 50) {
        return 0;
    } if (tamanho == 4) {
        if (token[3] != ',') {
            return 0;
        }
    }
    return 1;
}

int final_ser_tipo_label();
int final_ser_tipo_registrador();
int verifica_label();
int verifica_numero();
int verificar_inicio_do_label_e_fim_ser_numero(char instrucao[], int quantidade_partes) {
    char copia_instrucao[50];
    strcpy(copia_instrucao, instrucao);

    char *token = strtok(copia_instrucao, " ");

    if (final_ser_tipo_registrador(token)) {
        return quantidade_partes;
    } else if (strcmp(token, "jr") == 0) {
        token = strtok(NULL, " ");
        if (strcmp(token, "$ra") == 0) {
            return quantidade_partes;
        }
    } else if (final_ser_tipo_label(token)) {
        for (int i = 1; i < quantidade_partes; i++) {
        token = strtok(NULL, " ");
        if (i+1 == quantidade_partes) {
            if (verifica_label(token)) {
                return quantidade_partes;
            }
        }
    }
    } else {
        for (int i = 1; i < quantidade_partes; i++) {
            token = strtok(NULL, " ");
            if (i+1 == quantidade_partes) {
                if (verifica_numero(token)) {
                    return quantidade_partes;
                }
            }
        }
    }
    return 0;
} int final_ser_tipo_registrador(char token[]) {
    return strcmp(token, "add") == 0 || strcmp(token, "sub") == 0 || strcmp(token, "mul") == 0 || strcmp(token, "div") == 0;
} int final_ser_tipo_label(char token[]) {
    return strcmp(token, "la") == 0 || strcmp(token, "j") == 0 || strcmp(token, "jal") == 0;
} 
int verifica_label(char token[]) {
    if (token[0] > 122 || token[0] < 97) {
        return 0;
    }
    return 1;
} int verifica_numero(char token[]) {
    int tamanho = strlen(token);
    for (int i = 0; i < tamanho; i++) {
        if (token[0] == '-') {continue;}
        if (token[i] < 48 || token[i] > 57) {
            return 0;
        }
    }
    return 1;
}


// Executar instrucao
int operacao_add();
int operacao_mul();
int operacao_sub();
int operacao_div();
int operacao_addi();
int operacao_la();
int operacao_li();
int operacao_j_jal();
int operacao_jr();
int executar_instrucao(char instrucao[], int quantidade_partes, int *s0, int *s1, int *s2, int *pc) {
    char copia_instrucao[50];
    strcpy(copia_instrucao, instrucao);

    char *operacao = strtok(copia_instrucao, " ");

    char *registrador1;
    char *registrador2;
    char *registrador3;

    if (quantidade_partes == 4) {
        registrador1 = strtok(NULL, " ");
        registrador2 = strtok(NULL, " ");
        registrador3 = strtok(NULL, " ");
        
        if (registrador1[2] == registrador2[2] || registrador1[2] == registrador3[2]) {return 0;}

        char valor_registrador1 = registrador1[2];
        char valor_registrador2 = registrador2[2];

        if (strcmp(operacao, "add") == 0) {
            if (operacao_add(valor_registrador1, s0, s1, s2)) {
                return 1;
            }
        }
        if (strcmp(operacao, "mul") == 0) {
            if (operacao_mul(valor_registrador1, s0, s1, s2)) {
                return 1;
            }
        }
        if (strcmp(operacao, "sub") == 0) {
            if (operacao_sub(valor_registrador1, valor_registrador2, s0, s1, s2)) {
                return 1;
            }
        }
        if (strcmp(operacao, "div") == 0) {
            if (operacao_div(valor_registrador1, valor_registrador2, s0, s1, s2)) {
                return 1;
            }
        }
        if (strcmp(operacao, "addi") == 0) {
            if (operacao_addi(valor_registrador1, valor_registrador2, registrador3, s0, s1, s2)) {
                return 1;
            }
        }
    } 
    
    if (quantidade_partes == 3) {
        registrador1 = strtok(NULL, " ");
        registrador2 = strtok(NULL, " ");

        char valor_registrador1 = registrador1[2];

        if (strcmp(operacao, "la") == 0) {
            if (operacao_la(valor_registrador1, registrador2, s0, s1, s2)) {
                return 1;
            }
        }
        if (strcmp(operacao, "li") == 0) {
            if (operacao_li(valor_registrador1, registrador2, s0, s1, s2)) {
                return 1;
            }
        }
    }

    if (quantidade_partes == 2) {
        registrador1 = strtok(NULL, " ");

        if (strcmp(operacao, "j") == 0) {
            if (operacao_j_jal(registrador1)) {
                *pc = -4;
                return 1;
            }
        }
        if (strcmp(operacao, "jr") == 0) {
            if (operacao_jr(registrador1)) {
                *pc = -4;
                return 1;
            }
        }
        if (strcmp(operacao, "jal") == 0) {
            if (operacao_j_jal(registrador1)) {
                *pc = -4;
                return 1;
            }
        }
    }
    return 0;
} 

int operacao_add(int valor_registrador1, int *s0, int *s1, int *s2) {
    if (valor_registrador1 == '0') {
        *s0 = *s1 + *s2;
        return 1;
    } if (valor_registrador1 == '1') {
        *s1 = *s0 + *s2;
        return 1;
    } if (valor_registrador1 == '2'){
        *s2 = *s0 + *s1;
        return 1;
    }

    return 0;
}

int operacao_mul(int valor_registrador1, int *s0, int *s1, int *s2) {
    if (valor_registrador1 == '0') {
        *s0 = *s1 * *s2;
        return 1;
    } if (valor_registrador1 == '1') {
        *s1 = *s0 * *s2;
        return 1;
    } if (valor_registrador1 == '2'){
        *s2 = *s0 * *s1;
        return 1;
    }
    return 0;
}

int operacao_sub(int valor_registrador1, int valor_registrador2, int *s0, int *s1, int *s2) {
    if (valor_registrador1 == '0') {
        if (valor_registrador2 == '1') {
            *s0 = *s1 - *s2;
            return 1;
        } else {
            *s0 = *s2 - *s1;
            return 1;
        }    
    } if (valor_registrador1 == '1') {
        if (valor_registrador2 == '0') {
            *s1 = *s0 - *s2;
            return 1;
        } else {
            *s1 = *s2 - *s0;
            return 1;
        }
    } if (valor_registrador1 == '2') {
        if (valor_registrador2 == '0') {
            *s2 = *s0 - *s1;
            return 1;
        } else {
            *s2 = *s1 - *s0;
            return 1;
        }
    }
    return 0;
}

int operacao_div(int valor_registrador1, int valor_registrador2, int *s0, int *s1, int *s2) {
    if (valor_registrador1 == '0') {
        if (valor_registrador2 == '1') {
            *s0 = *s1 / *s2;
            return 1;
        } else {
            *s0 = *s2 / *s1;
            return 1;
        }    
    } if (valor_registrador1 == '1') {
        if (valor_registrador2 == '0') {
            *s1 = *s0 / *s2;
            return 1;
        } else {
            *s1 = *s2 / *s0;
            return 1;
        }
    } if (valor_registrador1 == '2') {
        if (valor_registrador2 == '0') {
            *s2 = *s0 / *s1;
            return 1;
        } else {
            *s2 = *s1 / *s0;
            return 1;
        }
    }
    return 0;
}

int char_para_int();
int char_para_int_negativo();
int operacao_addi(int valor_registrador1, int valor_registrador2, char valor[], int *s0, int *s1, int *s2) {
    if (valor[0] == '-' && strlen(valor) > 4) {
        return 0;
    } else if (valor[0] == '-') {
        int numero = char_para_int_negativo(valor);
        numero *= -1;

        if (valor_registrador1 == '0') {
            if (valor_registrador2 == '0') {
                *s0 = *s0 + numero;
                return 1;
            } else if (valor_registrador2 == '1') {
                *s0 = *s1 + numero;
                return 1;
            } else {
                *s0 = *s2 + numero;
                return 1;
            }
        } if (valor_registrador1 == '1') {
            if (valor_registrador2 == '0') {
                *s1 = *s0 + numero;
                return 1;
            } else if (valor_registrador2 == '1') {
                *s1 = *s1 + numero;
                return 1;
            } else {
                *s1 = *s2 + numero;
                return 1;
            }
        } if (valor_registrador1 == '2') {
            if (valor_registrador2 == '0') {
                *s2 = *s0 + numero;
                return 1;
            } else if (valor_registrador2 == '1') {
                *s2 = *s1 + numero;
                return 1;
            } else {
                *s2 = *s2 + numero;
                return 1;
            }
        }
    }
    

    if (strlen(valor) > 3) {return 0;}

    int numero = char_para_int(valor);

    if (valor_registrador1 == '0') {
        if (valor_registrador2 == '0') {
            *s0 = *s0 + numero;
            return 1;
        } else if (valor_registrador2 == '1') {
            *s0 = *s1 + numero;
            return 1;
        } else {
            *s0 = *s2 + numero;
            return 1;
        }
    } if (valor_registrador1 == '1') {
        if (valor_registrador2 == '0') {
            *s1 = *s0 + numero;
            return 1;
        } else if (valor_registrador2 == '1') {
            *s1 = *s1 + numero;
            return 1;
        } else {
            *s1 = *s2 + numero;
            return 1;
        }
    } if (valor_registrador1 == '2') {
        if (valor_registrador2 == '0') {
            *s2 = *s0 + numero;
            return 1;
        } else if (valor_registrador2 == '1') {
            *s2 = *s1 + numero;
            return 1;
        } else {
            *s2 = *s2 + numero;
            return 1;
        }
    }
    return 0;
} int char_para_int_negativo(char valor[]) {
    int centena = 0, dezena = 0, unidade = 0;

    int tamanho = strlen(valor);

    if (tamanho == 4) {
        for (int i = 0; i < 10; i++) {
            if (valor[1] == 48+i) {
                centena = i;
            }
        }
        for (int i = 0; i < 10; i++) {
            if (valor[2] == 48+i) {
                dezena = i;
            }
        }
        for (int i = 0; i < 10; i++) {
            if (valor[3] == 48+i) {
                unidade = i;
            }
        }
    } else if (tamanho == 3) {
        for (int i = 0; i < 10; i++) {
            if (valor[1] == 48+i) {
                dezena = i;
            }
        }
        for (int i = 0; i < 10; i++) {
            if (valor[2] == 48+i) {
                unidade = i;
            }
        }
    } else if (tamanho == 2) {
        for (int i = 0; i < 10; i++) {
            if (valor[1] == 48+i) {
                unidade = i;
            }
        }
    }
    return 100 * centena + 10 * dezena + unidade;
} int char_para_int(char valor[]) {
    int centena = 0, dezena = 0, unidade = 0;

    int tamanho = strlen(valor);

    if (tamanho == 3) {
        for (int i = 0; i < 10; i++) {
            if (valor[0] == 48+i) {
                centena = i;
            }
        }
        for (int i = 0; i < 10; i++) {
            if (valor[1] == 48+i) {
                dezena = i;
            }
        }
        for (int i = 0; i < 10; i++) {
            if (valor[2] == 48+i) {
                unidade = i;
            }
        }
    } else if (tamanho == 2) {
        for (int i = 0; i < 10; i++) {
            if (valor[0] == 48+i) {
                dezena = i;
            }
        }
        for (int i = 0; i < 10; i++) {
            if (valor[1] == 48+i) {
                unidade = i;
            }
        }
    } else if (tamanho == 1) {
        for (int i = 0; i < 10; i++) {
            if (valor[0] == 48+i) {
                unidade = i;
            }
        }
    }
    return 100 * centena + 10 * dezena + unidade;
}

int operacao_la(int valor_registrador1, char label[], int *s0, int *s1, int *s2) {
    if (strcmp(label, "var") != 0) {return 0;}

    if (valor_registrador1 == '0') {
        *s0 = 6422296;
        return 1;
    } if (valor_registrador1 == '1') {
        *s1 = 6422296;
        return 1;
    } if (valor_registrador1 == '2'){
        *s2 = 6422296;
        return 1;
    }
    return 0;
}

int operacao_li(int valor_registrador1, char label[], int *s0, int *s1, int *s2) {
    if (label[0] == '-' && strlen(label) > 4) {
        return 0;
    } else if (label[0] == '-') {
        int numero = char_para_int_negativo(label);
        numero *= -1;

        if (valor_registrador1 == '0') {
            *s0 = numero;
            return 1;
        } if (valor_registrador1 == '1') {
            *s1 = numero;
            return 1;
        } if (valor_registrador1 == '2'){
            *s2 = numero;
            return 1;
        }
    }

    if (strlen(label) > 3) {return 0;}

    int numero = char_para_int(label);

    if (valor_registrador1 == '0') {
        *s0 = numero;
        return 1;
    } if (valor_registrador1 == '1') {
        *s1 = numero;
        return 1;
    } if (valor_registrador1 == '2'){
        *s2 = numero;
        return 1;
    }
    return 0;
}

int operacao_j_jal(char label[]) {
    if (strcmp(label, "main") == 0) {return 1;}
    return 0;
}

int operacao_jr(char label[]) {
    if (strcmp(label, "$ra") == 0) {return 1;}
    return 0;
}


// Emulador
int main() {
    int s0 = 0, s1 = 1, s2 = 2, pc = 0;
    char log_instrucoes[21][30];
    
    menu_inicial();

    while (1) {
        mostrar_interface_pc_instrucoes_registradores(s0, s1, s2, pc, log_instrucoes);

        if (pc == 80) {break;}

        char instrucao[30];
        pegar_instrucao(instrucao, pc);
        
        int quantidade_partes;

        if (verificar_instrucao(instrucao, &quantidade_partes)) {
            if (executar_instrucao(instrucao, quantidade_partes, &s0, &s1, &s2, &pc)) {
                atualizar_pc_log(&pc, log_instrucoes, instrucao);
            } else {
                instrucao_invalida();
            }
        } else {
            instrucao_invalida();
        }   
    }
    printf("Maximo de 20 instrucoes alcancado.\n");
    return 0;
}
