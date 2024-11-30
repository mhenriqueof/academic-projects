# include <stdio.h>
# include <stdlib.h>

typedef struct {
    int matricula;
    char sobrenome[20];
    char ano_nascimento[11];
} alunos;

int main() {

    int n_alunos;

    printf("Numero de alunos: ");
    scanf("%d", &n_alunos);

    alunos *aluno = (alunos *) malloc(n_alunos * sizeof(alunos));
    if (aluno == NULL) {
        return 1;
    }

    for (int i = 0; i < n_alunos; i++) {
        printf("--- Aluno %d ---\n", i+1);
        
        printf("Matricula: ");
        scanf("%d", &(aluno+i)->matricula);

        fflush(stdin);
        printf("Sobrenome: ");
        gets((aluno+i)->sobrenome);

        fflush(stdin);
        printf("Ano de nascimento: ");
        gets((aluno+i)->ano_nascimento);

        printf("\n");
    }

    for (int i = 0; i < n_alunos; i++) {
        printf("Matricula %d\n", aluno[i].matricula);
        printf("%s\n", aluno[i].sobrenome);
        printf("%s\n", aluno[i].ano_nascimento);
        printf("\n");
    }

    free(aluno);

    return 0;
}
