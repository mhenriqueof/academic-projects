// Sabe-se que a direção de uma determinada escolinha faz a distribuição deseus alunos de acordo com as idades dos mesmos. Dessa forma, os alunos sãodistribuídos nas seguintes turmas de acordo com a classificação a seguir

#include <stdio.h>

int main() {
    
    char turma;
    int idade;
    
    printf("Idade da criança: ");
    scanf("%d", &idade);
    
    if (idade < 0) {
        printf("Idade inválida.");
    } else if (idade > 10 || idade < 4) {
        printf("Não há turmas para esta idade.");
    } else {
        if (idade >= 9) {
            turma = 'C';
        } else if (idade >= 6) {
            turma = 'B';
        } else {
            turma = 'A';
        }
        printf("Aluno será da Turma %c.", turma);
    }
    
    return 0;
}
