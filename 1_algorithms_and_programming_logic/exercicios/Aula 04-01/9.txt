// (Beecrowd | 2344) Rosy é uma talentosa professora do EnsinoMédio que já ganhou muitos prêmios pela qualidade de sua aula. Seureconhecimento foi tamanho que foi convidada a dar aulas em uma escola daInglaterra. Mesmo falando bem inglês, Rosy ficou um pouco apreensiva com aresponsabilidade, mas resolveu aceitar a proposta e encará-la como um bomdesafio.Tudo ocorreu bem para Rosy até o dia da prova. Acostumada a darnotas de 0 (zero) a 100 (cem), ela fez o mesmo na primeira prova dos alunosda Inglaterra. No entanto, os alunos acharam estranho, pois na Inglaterra osistema de notas é diferente: as notas devem ser dadas como conceitos de A aE. O conceito A é o mais alto, enquanto o conceito E é o mais baixo.Conversando com outros professores, ela recebeu a sugestão de utilizara seguinte tabela, relacionando as notas numéricas com as notas de conceitos

#include <stdio.h>

int main() {
    
    float grade;
    
    printf("Grade: ");
    scanf("%f", &grade);
    
    if (grade > 100 || grade < 0) {
        printf("Invalid grade.");
    } else if (grade == 0) {
        printf("E");
    } else if (grade >= 86) {
        printf("A");
    } else if (grade >= 61) {
        printf("B");
    } else if (grade >= 36) {
        printf("C");
    } else {
        printf("D");
    }

    return 0;
}
