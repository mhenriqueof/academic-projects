# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <locale.h>
# include <windows.h>
# include <unistd.h>
# include <time.h>

int numero_clientes;
int n_pedidos =0;

typedef struct {
	char nome[50];
	char cpf[12];
	char data_nascimento[11];
	char email[50];
	char endereco[50];
	char status[8];
} dados_clientes;

typedef struct {
	int id_pedido;
	char data_pedido[12];
	char instrumento[50];
	int quantidade;
	char metodo_pagamento[50];
	char status_pedido[50];
	float valor_total;
} dados_pedidos;

// Geral

void linha() {
	printf("------------------------------------------------\n\n");
}

int contar_clientes() {
    FILE *arquivo = fopen("clientes.txt", "r");
	if (arquivo == NULL) {
		arquivo = fopen("clientes.txt", "w");
		if (arquivo == NULL) {
			printf("Falha ao abrir o arquivo.\n");
        	exit(1);
		}
    }

    int contador = 0;
    char linha[500];

    while (fgets(linha, sizeof(linha), arquivo)) {
        contador++;
    }

    fclose(arquivo);
    return contador;
}

int ano_atual() {
    time_t agora;
    time(&agora);

    struct tm *tempo_atual = localtime(&agora);

    int ano_atual = tempo_atual->tm_year + 1900;

    return ano_atual;
}

int verificar_cpf(char string[]) {
    if (strlen(string) != 11) {
        return 0;
    }
    
    for (int i = 0; i < 11; i++) {
        int ascii_posicao = string[i];
        if (ascii_posicao < 48 || ascii_posicao > 57) {
            return 0;
        }
    }

    FILE *arquivo = fopen("clientes.txt", "r");
    if (arquivo == NULL) {
        printf("Falha ao abrir o arquivo.\n");
        exit(1);
    }

    char linha[256];
    while (fgets(linha, sizeof(linha), arquivo)) {
        char *cpf = strtok(linha, ",");
        cpf = strtok(NULL, ",");

		while (*cpf == ' ') cpf++;

        if (strcmp(cpf, string) == 0) {
            fclose(arquivo);
            printf("CPF j� cadastrado.\n");
            return 2;
        }
    }

    fclose(arquivo);
    return 1;
}

int verificar_se_rua_avenida(char string[]) {
	if (strstr(string, "rua") == NULL && strstr(string, "Rua") == NULL && strstr(string, "RUA") == NULL && strstr(string, "avenida") == NULL && strstr(string, "Avenida") == NULL && strstr(string, "AVENIDA") == NULL) {
		return 0;
	} else if (strstr(string, " ") == NULL) {
		return 0;
	}
	return 1;
}



// Clientes - Henrique Oliveira

void adicionar_cliente();
void listar_clientes();
void consultar_cliente();
void desativar_cliente();
void excluir_cliente();
void gerenciar_clientes() {
	int opcao = -1;

	while (opcao != 0) {
		printf("-- Gerenciamento de Clientes --\n");
		printf("[1] Adicionar novo cliente\n");
		printf("[2] Listar todos os clientes\n");
		printf("[3] Consultar cliente a partir do CPF\n");
		printf("[4] Desativar cliente a partir do CPF\n");
		printf("[5] Excluir cliente a partir do CPF\n");
		printf("[0] Voltar para o Menu Principal\n");
		scanf("%d", &opcao);

		switch (opcao) {
			case 0:
				linha();
				return;
			case 1:
				adicionar_cliente();
				break;
			case 2:
				listar_clientes();
				break;
			case 3:
				consultar_cliente();
				break;
			case 4:
				desativar_cliente();
				break;
			case 5:
				excluir_cliente();
				break;
			default:
				printf("Op��o inv�lida.\n");
		}
		sleep(2);
		linha();
	}
}


int coletar_dados_cliente();
void atualizar_numero_clientes();
void enviar_dados_cliente_para_arquivo();
void adicionar_cliente() {
	dados_clientes *dado_cliente = (dados_clientes*) malloc(1 * sizeof(dados_clientes));
	if (dado_cliente == NULL) {
		printf("Falha no alocar.\n");
		exit(1);
	}

	int coletou_todos_os_dados = coletar_dados_cliente(dado_cliente);
	if (coletou_todos_os_dados) {
		atualizar_numero_clientes();
		enviar_dados_cliente_para_arquivo(dado_cliente);
	}

	free(dado_cliente);
} int coletar_dados_cliente(dados_clientes *dado_cliente) {
	printf("Cadastro dispon�vel apenas para clientes maiores de 18 anos.\n");
	// Coletar nome e sobrenome
	while (1) {
		printf("Digite o nome e sobrenome: ");
		fflush(stdin);
		gets(dado_cliente->nome);
		
		if (strstr(dado_cliente->nome, " ") != NULL) {
			break;
		}		
		printf("Nome e sobrenome inv�lido.\n");
		sleep(1.5);
	}
	
	// Coletar CPF
	while (1) {
		printf("Digite o CPF: ");
		fflush(stdin);
		gets(dado_cliente->cpf);

		int flag = verificar_cpf(dado_cliente->cpf);
		
		if (flag == 1) {
			break;
		} else if (flag == 2) {
			return 0;
		}
		printf("CPF inv�lido.\n");
		sleep(1.5);
	}

	// Data de nascimento
	int dia, mes, ano;
	printf("Data de nascimento [Somente n�mero]\n");
	while (1) {
		fflush(stdin);
		printf("Dia: ");
		scanf("%d", &dia);
		if (dia > 0 && dia < 32) {
			break;
		}
		printf("Dia inv�lido.\n");
		sleep(1.5);
	} 
	while (1) {
		fflush(stdin);
		printf("M�s: ");
		scanf("%d", &mes);
		if (mes > 0 && mes < 13) {
			break;
		}
		printf("M�s inv�lido.\n");
		sleep(1.5);
	} 
	while (1) {
		fflush(stdin);
		printf("Ano: ");
		scanf("%d", &ano);
		if (ano > 1899 && ano < 2025) {
			break;
		}
		printf("Ano inv�lido.\n");
		sleep(1.5);
	}
	if (ano_atual() - ano < 18) {
		printf("Cliente menor de 18 anos.\n");
		return 0;
	}

	sprintf(dado_cliente->data_nascimento, "%02d/%02d/%d", dia, mes, ano);
	
	// Coletar email
	while (1) {
		printf("Digite o email: ");
		fflush(stdin);
		gets(dado_cliente->email);
		
		if (strstr(dado_cliente->email, "@") != NULL && strstr(dado_cliente->email, ".") != NULL) {
			break;
		}		
		printf("Email inv�lido.\n");
		sleep(1.5);
	}

	// Coletar endere�o
	while (1) {
		printf("Digite o endere�o: ");
		fflush(stdin);
		gets(dado_cliente->endereco);
		
		if (verificar_se_rua_avenida(dado_cliente->endereco)) {
			break;
		}		
		printf("Endere�o inv�lido.\n");
		sleep(1.5);
	}

	// Adicionar status do cliente
	sprintf(dado_cliente->status, "Ativo");

	return 1;
} void atualizar_numero_clientes() {
    FILE *arquivo = fopen("numero_clientes.txt", "w");
    if (arquivo == NULL) {
        printf("Falha ao abrir o arquivo.\n");
        exit(1);
    }
    
    numero_clientes += 1;
    fprintf(arquivo, "%d", numero_clientes);
    
    fclose(arquivo);
} void enviar_dados_cliente_para_arquivo(dados_clientes *dado_cliente) {
	FILE *arquivo =  fopen("clientes.txt", "a+");
	if (arquivo == NULL) {
		printf("Falha ao abrir o arquivo.\n");
		exit(1);
	}

	fprintf(arquivo, "%s, %s, %s, %s, %s, %s\n",
	dado_cliente->nome, dado_cliente->cpf, dado_cliente->data_nascimento, dado_cliente->email, dado_cliente->endereco, dado_cliente->status);

	fclose(arquivo);

	printf("- Cliente %d cadastrado com sucesso! -\n", numero_clientes);
}


void listar_por_nome();
void listar_por_cpf();
void listar_clientes() {
    FILE *arquivo = fopen("clientes.txt", "r");
    if (arquivo == NULL) {
        printf("Falha ao abrir o arquivo.\n");
        exit(1);
    }

	int i = 0;
	dados_clientes *clientes = (dados_clientes*) malloc(numero_clientes * sizeof(dados_clientes));
    while (fscanf(arquivo, "%[^,], %[^,], %[^,], %[^,], %[^,], %[^\n]\n", 
	clientes[i].nome, clientes[i].cpf, clientes[i].data_nascimento, clientes[i].email, clientes[i].endereco, clientes[i].status) != EOF) {
		i++;
    }
    fclose(arquivo);

    printf("- Ordem de listagem dos %d clientes -\n", numero_clientes);
    printf("[1] Por Nome\n");
    printf("[2] Por CPF\n");

    int opcao;
	scanf("%d", &opcao);
	switch (opcao) {
		case 1:
			listar_por_nome(clientes);
			break;
		case 2:
			listar_por_cpf(clientes);
			break;
		default:
			printf("Op��o inv�lida.\n");
			return;
	}

    printf("Clientes cadastrados:\n");
    for (int j = 0; j < i; j++) {
        printf("Nome: %s, CPF: %s, Data de Nascimento: %s, Email: %s, Endere�o: %s, Status: %s\n",
		clientes[j].nome, clientes[j].cpf, clientes[j].data_nascimento, clientes[j].email, clientes[j].endereco, clientes[j].status);
    }
	free(clientes);
} void listar_por_nome(dados_clientes clientes[]) {
	for (int j = 0; j < numero_clientes - 1; j++) {
		for (int k = j + 1; k < numero_clientes; k++) {
			if (strcmp(clientes[j].nome, clientes[k].nome) > 0) {
				dados_clientes temp = clientes[j];
				clientes[j] = clientes[k];
				clientes[k] = temp;
			}
		}
	}
} void listar_por_cpf(dados_clientes clientes[]) {
	for (int j = 0; j < numero_clientes - 1; j++) {
		for (int k = j + 1; k < numero_clientes; k++) {
			if (strcmp(clientes[j].cpf, clientes[k].cpf) > 0) {
				dados_clientes temp = clientes[j];
				clientes[j] = clientes[k];
				clientes[k] = temp;
			}
		}
	}
}


void consultar_cpf_arquivo();
void consultar_cliente() {
	char cpf_procurado[11];
	fflush(stdin);
	printf("Procurar cliente pelo CPF: ");
	gets(cpf_procurado);

	consultar_cpf_arquivo(cpf_procurado);    
} void consultar_cpf_arquivo(char cpf_procurado[]) {
	FILE *arquivo = fopen("clientes.txt", "r");
    if (arquivo == NULL) {
        printf("Falha ao abrir o arquivo.\n");
        exit(1);
    }

	char linha[256];
    int encontrado = 0;
	dados_clientes cliente;
    while (fgets(linha, sizeof(linha), arquivo)) {
        sscanf(linha, "%[^,], %[^,], %[^,], %[^,], %[^,], %s", 
		cliente.nome, cliente.cpf, cliente.data_nascimento, cliente.email, cliente.endereco, cliente.status);

        if (strcmp(cliente.cpf, cpf_procurado) == 0) {
            encontrado = 1;
			break;
        }
    }

	if (encontrado) {
		printf("Nome: %s, CPF: %s, Data de Nascimento: %s, Email: %s, Endere�o: %s, Status: %s\n", 
		cliente.nome, cliente.cpf, cliente.data_nascimento, cliente.email, cliente.endereco, cliente.status);
	} else {
		printf("Cliente com CPF %s n�o encontrado.\n", cpf_procurado);
	}
}


void alterar_status_para_inativo();
void desativar_cliente() {
	char cpf_procurado[11];
	fflush(stdin);
	printf("Desativar cliente pelo CPF: ");
	gets(cpf_procurado);

	alterar_status_para_inativo(cpf_procurado); 
} void alterar_status_para_inativo(char cpf_procurado[]) {
    FILE *arquivo = fopen("clientes.txt", "r");
    if (arquivo == NULL) {
        printf("Falha ao abrir o arquivo.");
        return;
    }

    FILE *temp = fopen("temp.txt", "w");
    if (temp == NULL) {
        printf("Falha ao abrir o arquivo tempor�rio.");
        fclose(arquivo);
        return;
    }

    char linha[256];
    int encontrado = 0;
    while (fgets(linha, sizeof(linha), arquivo)) {
        dados_clientes cliente;
        sscanf(linha, "%[^,], %[^,], %[^,], %[^,], %[^,], %s", 
		cliente.nome, cliente.cpf, cliente.data_nascimento, cliente.email, cliente.endereco, cliente.status);

        if (strcmp(cliente.cpf, cpf_procurado) == 0) {
            strcpy(cliente.status, "Inativo");
            encontrado = 1;
        }

        fprintf(temp, "%s, %s, %s, %s, %s, %s\n", 
		cliente.nome, cliente.cpf, cliente.data_nascimento, cliente.email, cliente.endereco, cliente.status);
    }

    fclose(arquivo);
    fclose(temp);

    if (encontrado) {
        remove("clientes.txt");
        rename("temp.txt", "clientes.txt");
        printf("Status do cliente com CPF %s alterado para Inativo.\n", cpf_procurado);
    } else {
        remove("temp.txt");
        printf("Cliente com CPF %s n�o encontrado.\n", cpf_procurado);
    }
}


void excluir_cliente_por_cpf();
void excluir_cliente() {
	char cpf_procurado[11];
	fflush(stdin);
	printf("Excluir cliente pelo CPF: ");
	gets(cpf_procurado);

	excluir_cliente_por_cpf(cpf_procurado);
} void excluir_cliente_por_cpf(char cpf_procurado[]) {
    FILE *arquivo = fopen("clientes.txt", "r");
    if (arquivo == NULL) {
        printf("Falha ao abrir o arquivo.");
        return;
    }

    FILE *temp = fopen("temp.txt", "w");
    if (temp == NULL) {
        printf("Falha ao abrir o arquivo tempor�rio.");
        fclose(arquivo);
        return;
    }

    char linha[256];
    int encontrado = 0;
    while (fgets(linha, sizeof(linha), arquivo)) {
        dados_clientes cliente;
        sscanf(linha, "%[^,], %[^,], %[^,], %[^,], %[^,], %s", 
		cliente.nome, cliente.cpf, cliente.data_nascimento, cliente.email, cliente.endereco, cliente.status);

        if (strcmp(cliente.cpf, cpf_procurado) != 0) {
            fprintf(temp, "%s, %s, %s, %s, %s, %s\n",
			cliente.nome, cliente.cpf, cliente.data_nascimento,cliente.email, cliente.endereco, cliente.status);
        } else {
            encontrado = 1;
        }
    }

    fclose(arquivo);
    fclose(temp);

    if (encontrado) {
        remove("clientes.txt");
        rename("temp.txt", "clientes.txt");
        printf("Cliente com CPF %s exclu�do com sucesso.\n", cpf_procurado);
    } else {
        remove("temp.txt");
        printf("Cliente com CPF %s n�o encontrado.\n", cpf_procurado);
    }
}



// Pedidos - Gabriel Cardoso

void adicionar_novo_pedido();
void listar_pedidos();
void coletar_dados_pedido();
void enviar_dados_pedido_para_arquivo();
void listar_pedidos();

void gerenciar_pedidos(){
	
	int opcao=-1;
	
	while(opcao != 0){
		printf("-- Gerenciamento de Pedidos --\n");
		printf("[1] Adicionar novo Pedido\n");
		printf("[2] Listar todos as Pedidos\n");
		printf("[0] Sair\n");
		scanf("%d", &opcao);
		switch(opcao){
			case 1:
				adicionar_novo_pedido();
				break;
			case 2:
				listar_pedidos();
				break;
			case 0:
				break;
			default:
				printf("Op��o Inv�lida!!.");
		}
			sleep(2);
			linha();
	
	}

}

void adicionar_novo_pedido(){

	int encontrado = 0;
	char cpf_procurar[11];

	printf("Digite o CPF do cliente: ");
	fflush(stdin);
	gets(cpf_procurar);

	FILE *arquivo = fopen("clientes.txt", "r");
	if (arquivo == NULL) {
		printf("Falha ao abrir o arquivo.\n");
		exit(1);
	}

	char linha[256];
	while (fgets(linha, sizeof(linha), arquivo)) {
		char *cpf = strtok(linha, ",");
		cpf = strtok(NULL, ",");

		while (*cpf == ' ') cpf++;

		if (strcmp(cpf, cpf_procurar) == 0) {
			fclose(arquivo);
			encontrado = 1;
		}
	}
	
	if (encontrado == 0) {
		printf("CPF n�o cadastrado.\n");
		return;
	}

	
	dados_pedidos *dado_pedido = (dados_pedidos*)malloc(1 *sizeof(dados_pedidos));
	if (dado_pedido == NULL) {
		printf("Falha no Alocamento\n");
		exit(1);
	}
		
	coletar_dados_pedido(dado_pedido);
    enviar_dados_pedido_para_arquivo(dado_pedido);
    	
	printf("- Pedido %d cadastrado com sucesso! -\n", n_pedidos+1);
	free(dado_pedido);
	n_pedidos += 1;
	
}

void coletar_dados_pedido(dados_pedidos *dado_pedido) {
    int opcao;
    
    float preco_instrumento = 0.0;

    
    printf(" - Instrumentos Dispon�veis -\n");
    printf("[1] -- Guitarra Tagima.   valor:r$1300.00\n");
    printf("[2] -- Viol�o Strinberg.  valor:r$1500.00\n");
    printf("[3] -- Bateria Odery.     valor:r$4300.00\n");
    printf("[4] -- Teclado Yamaha.    valor:r$2300.00\n");
 

    printf("Digite a Op��o: ");
    scanf("%d", &opcao);
    fflush(stdin); 
    
    if (opcao == 1) {
        preco_instrumento = 1300.0;
      
        strcpy(dado_pedido->instrumento, "Guitarra");
        
        printf(" -- %s -- \n", dado_pedido->instrumento);
        printf("Digite a quantidade: ");
        scanf("%d", &dado_pedido->quantidade);
        fflush(stdin);
        
        dado_pedido->valor_total = preco_instrumento * dado_pedido->quantidade;
        
        while(1){
        	
	        printf("Data Atual DD/MM/AA: ");
	        scanf("%s", dado_pedido->data_pedido);
	        fflush(stdin);
	        
	        	if (strstr(dado_pedido->data_pedido, "/") != NULL) {
					break;
				}		
				printf("Formato inv�lido.\n");
				sleep(2);
			}
			
			int opcao;
	        
		while (1) {
	        printf("[1] -- Pix\n");
	        printf("[2] -- Cart�o D�bito ou Cr�dito\n");
	        printf("[3] -- Boleto\n");
	        printf("M�todo de Pagamento: ");
	        
	   
	        if (scanf("%d", &opcao) != 1) {
	            printf("Erro! Por favor, insira um n�mero v�lido.\n");
	            while (getchar() != '\n'); 
	            continue;
	        }
	
	        switch (opcao) {
	            case 1:
	                strcpy(dado_pedido->metodo_pagamento, "Pix");
	                strcpy(dado_pedido->status_pedido, "Ativo");
	                break;
	            case 2:
	                strcpy(dado_pedido->metodo_pagamento, "Cart�o");
	                strcpy(dado_pedido->status_pedido, "Ativo");
	                break;
	            case 3:
	                strcpy(dado_pedido->metodo_pagamento, "Boleto");
	                strcpy(dado_pedido->status_pedido, "Ativo");
	                break;
	            default:
	                printf("Erro! M�todo de pagamento inv�lido.\n");
	                continue; 
	        }
	
	       
	        break;
    }
       
        
    }else if(opcao == 2){
    	
    	preco_instrumento=1500.0;

    	 
    	strcpy(dado_pedido->instrumento, "Viol�o");
    	printf(" -- %s -- \n", dado_pedido->instrumento);
        printf("Digite a quantidade: ");
        scanf("%d", &dado_pedido->quantidade);
         dado_pedido->valor_total = preco_instrumento * dado_pedido->quantidade;
        
        printf("Data Atual DD/MM/AA: ");
        scanf("%s", dado_pedido->data_pedido);
        fflush(stdin);
        
       
        while(1){
        	
	        printf("Data Atual DD/MM/AA: ");
	        scanf("%s", dado_pedido->data_pedido);
	        fflush(stdin);
	        
	        	if (strstr(dado_pedido->data_pedido, "/") != NULL) {
					break;
				}		
				printf("Formato inv�lido.\n");
				sleep(2);
			}
			
			int opcao;
	        
		while (1) {
	        printf("[1] -- Pix\n");
	        printf("[2] -- Cart�o D�bito ou Cr�dito\n");
	        printf("[3] -- Boleto\n");
	        printf("M�todo de Pagamento: ");
	        
	   
	        if (scanf("%d", &opcao) != 1) {
	            printf("Erro! Por favor, insira um n�mero v�lido.\n");
	            while (getchar() != '\n'); 
	            continue;
	        }
	
	        switch (opcao) {
	            case 1:
	                strcpy(dado_pedido->metodo_pagamento, "Pix");
	                strcpy(dado_pedido->status_pedido, "Ativo");
	                break;
	            case 2:
	                strcpy(dado_pedido->metodo_pagamento, "Cart�o");
	                strcpy(dado_pedido->status_pedido, "Ativo");
	                break;
	            case 3:
	                strcpy(dado_pedido->metodo_pagamento, "Boleto");
	                strcpy(dado_pedido->status_pedido, "Ativo");
	                break;
	            default:
	                printf("Erro! M�todo de pagamento inv�lido.\n");
	                continue; 
	        }
	
	       
	        break;
    }
        	
    	
	}else if(opcao == 3){
		
		preco_instrumento = 4300.0;
		
	
		strcpy(dado_pedido->instrumento, "Bateria");
    	printf(" -- %s -- \n", dado_pedido->instrumento);
        printf("Digite a quantidade: ");
        scanf("%d", &dado_pedido->quantidade);
         dado_pedido->valor_total = preco_instrumento * dado_pedido->quantidade;
        
        printf("Data Atual DD/MM/AA: ");
        scanf("%s", dado_pedido->data_pedido);
        fflush(stdin);
        
       
        while(1){
        	
	        printf("Data Atual DD/MM/AA: ");
	        scanf("%s", dado_pedido->data_pedido);
	        fflush(stdin);
	        
	        	if (strstr(dado_pedido->data_pedido, "/") != NULL) {
					break;
				}		
				printf("Formato inv�lido.\n");
				sleep(2);
		}
			
			int opcao;
	        
		while (1) {
	        printf("[1] -- Pix\n");
	        printf("[2] -- Cart�o D�bito ou Cr�dito\n");
	        printf("[3] -- Boleto\n");
	        printf("M�todo de Pagamento: ");
	        
	   
	        if (scanf("%d", &opcao) != 1) {
	            printf("Erro! Por favor, insira um n�mero v�lido.\n");
	            while (getchar() != '\n'); 
	            continue;
	        }
	
	        switch (opcao) {
	            case 1:
	                strcpy(dado_pedido->metodo_pagamento, "Pix");
	                strcpy(dado_pedido->status_pedido, "Ativo");
	                break;
	            case 2:
	                strcpy(dado_pedido->metodo_pagamento, "Cart�o");
	                strcpy(dado_pedido->status_pedido, "Ativo");
	                break;
	            case 3:
	                strcpy(dado_pedido->metodo_pagamento, "Boleto");
	                strcpy(dado_pedido->status_pedido, "Ativo");
	                break;
	            default:
	                printf("Erro! M�todo de pagamento inv�lido.\n");
	                continue; 
	        }
	
	       
	        break;
    }
		
	}else if(opcao == 4){
		
		 preco_instrumento = 2300.0;

		strcpy(dado_pedido->instrumento, "Teclado");
    	printf(" -- %s -- \n", dado_pedido->instrumento);
    	
        printf("Digite a quantidade: ");
        scanf("%d", &dado_pedido->quantidade);
        
         dado_pedido->valor_total = preco_instrumento * dado_pedido->quantidade;
        
        printf("Data Atual DD/MM/AA: ");
        scanf("%s", dado_pedido->data_pedido);
        fflush(stdin);
        
       
        while(1){
        	
	        printf("Data Atual DD/MM/AA: ");
	        scanf("%s", dado_pedido->data_pedido);
	        fflush(stdin);
	        
	        	if (strstr(dado_pedido->data_pedido, "/") != NULL) {
					break;
				}		
				printf("Formato inv�lido.\n");
				sleep(2);
		}
			
			int opcao;
	        
		while (1) {  
	        printf("[1] -- Pix\n");
	        printf("[2] -- Cart�o D�bito ou Cr�dito\n");
	        printf("[3] -- Boleto\n");
	        printf("M�todo de Pagamento: ");
	        
	   
	        if (scanf("%d", &opcao) != 1) {
	            printf("Erro! Por favor, insira um n�mero v�lido.\n");
	            while (getchar() != '\n'); 
	            continue;
	        }
	
	        switch (opcao) {
	            case 1:
	                strcpy(dado_pedido->metodo_pagamento, "Pix");
	                strcpy(dado_pedido->status_pedido, "Ativo");
	                break;
	            case 2:
	                strcpy(dado_pedido->metodo_pagamento, "Cart�o");
	                strcpy(dado_pedido->status_pedido, "Ativo");
	                break;
	            case 3:
	                strcpy(dado_pedido->metodo_pagamento, "Boleto");
	                strcpy(dado_pedido->status_pedido, "Ativo");
	                break;
	            default:
	                printf("Erro! M�todo de pagamento inv�lido.\n");
	                continue; 
	        }
	
	       
	        break;
        }
	
    }else{
    	
    	printf("Erro Tente Novamente!\n");
    	coletar_dados_pedido(dado_pedido);
    
    	
  
	}
    
}


void enviar_dados_pedido_para_arquivo(dados_pedidos *dado_pedido) {
    FILE *arquivo = fopen("pedidos.txt", "a+"); 
    if (arquivo == NULL) {
        printf("Falha ao abrir o arquivo.\n");
        exit(1);
    }

  
   	fprintf(arquivo, "%s, %d, %s, %s, %.2f, %s\n", dado_pedido->instrumento, dado_pedido->quantidade, dado_pedido->data_pedido, dado_pedido->metodo_pagamento,dado_pedido->valor_total, dado_pedido->status_pedido);

    fclose(arquivo);

}

void listar_pedidos() {
    FILE *file = fopen("pedidos.txt", "r");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    dados_pedidos pedido;

    printf("Lista de Pedidos:\n");
    linha();


    while (fscanf(file, "%49[^,],%d,%49[^,],%49[^,],%f,%6[^\n]\n",
                  pedido.instrumento, &pedido.quantidade, 
                  pedido.data_pedido, pedido.metodo_pagamento, 
                  &pedido.valor_total, pedido.status_pedido) != EOF) {
        printf("Instrumento: %s\n", pedido.instrumento);
        printf("Quantidade: %d\n", pedido.quantidade);
        printf("Data: %s\n", pedido.data_pedido);
        printf("Pagamento: %s\n", pedido.metodo_pagamento);
        printf("Valor Total: %.2f\n", pedido.valor_total);
        printf("Status: %s\n", pedido.status_pedido);
        linha();
    }

    printf("Todos os pedidos listados.\n");

    fclose(file);
}

   
int main() {
	
	setlocale(LC_ALL, "portuguese_Brazil");
	SetConsoleOutputCP (28591);
    SetConsoleCP(28591);

	numero_clientes = contar_clientes();
	
	int opcao = -1;
	while (opcao != 0) {
		printf("--- Laborat�rio dos Instrumentos ---\n");
		printf("[1] Gerenciar Clientes\n");
		printf("[2] Gerenciar Pedidos\n");
		printf("[0] Sair\n");
		scanf("%d", &opcao);
		
		switch (opcao) {
			case 1:
				gerenciar_clientes();
				break;
			case 2:
				gerenciar_pedidos();
				break;
			case 0:
				break;
			default:
				printf("Op��o inv�lida.\n");
		}
	}
}
