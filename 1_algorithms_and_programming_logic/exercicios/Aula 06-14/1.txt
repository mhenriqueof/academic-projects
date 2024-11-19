#include <stdio.h>

typedef struct {
    char nome[50];
    int idade;
    float salario;
    float experiencia;
    char cargo[50];
}funcionarios;

int main() {
    
    int tamanho = 3;
    float soma = 0, maior_exp = 0, maior_sal = 0;
    funcionarios funcionario[tamanho];
    
    for (int i = 0; i < tamanho; i++) {
        
        printf("--- Funcionario %d ---\n", i+1);
        
        fflush(stdin);
        printf("Nome: ");
        scanf("%s", funcionario[i].nome);
        
        printf("Idade: ");
        scanf("%d", &funcionario[i].idade);
        
        printf("Salario: ");
        scanf("%f", &funcionario[i].salario);
        
        printf("Experiencia: ");
        scanf("%f", &funcionario[i].experiencia);
        
        fflush(stdin);
        printf("Cargo: ");
        scanf("%s", funcionario[i].cargo);
        
        soma += funcionario[i].idade;
    }
    
    printf("Media das idades: %.2f\n", soma / tamanho);
    
    for (int i = 0; i < tamanho; i++) {
        if (funcionario[i].experiencia > maior_exp) {
            maior_exp = funcionario[i].experiencia;
        }
        if (funcionario[i].salario > maior_sal) {
            maior_sal = funcionario[i].salario;
        }
    }
    printf("\n");
    for (int i = 0; i < tamanho; i++) {
        if (funcionario[i].experiencia == maior_exp) {
            printf("%s\n", funcionario[i].nome);
        }
        if (funcionario[i].salario == maior_sal) {
            printf("%s\n", funcionario[i].cargo);
        }
    }
    
    return 0;
}
