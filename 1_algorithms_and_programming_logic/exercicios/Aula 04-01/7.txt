// Leia quatro números (N1, N2, N3, N4), cada um deles com umacasa decimal, correspondente às quatro notas de um aluno. Calcule a médiacom pesos 2, 3, 4 e 1, respectivamente, para cada uma destas notas e mostreesta média acompanhada pela mensagem "Media: ". Se esta média for maiorou igual a 7.0, imprima a mensagem "Aluno aprovado.". Se a média calculadafor inferior a 5.0, imprima a mensagem "Aluno reprovado.". Se a médiacalculada for um valor entre 5.0 e 6.9, inclusive estas, o programa deveimprimir a mensagem "Aluno em exame"

#include <stdio.h>

# define P1 2
# define P2 3
# define P3 4
# define P4 1

int main() {
    

    
    float n1, n2, n3, n4, media;
    
    printf("Nota 1: ");
    scanf("%f", &n1);
    
    printf("Nota 2: ");
    scanf("%f", &n2);
    
    printf("Nota 3: ");
    scanf("%f", &n3);
    
    printf("Nota 4: ");
    scanf("%f", &n4);
    

    media = ((n1 * P1) + (n2 * P2) + (n3 * P3) + (n1 * P4)) / 10;
    
    if (media > 10 || media < 0) {
        printf("Algum valor foi digitado errado.");
    } else if (media >= 7) {
        printf("Aluno aprovado.");
    } else if (media >= 5) {
        printf("Aluno em exame.");
    } else {
        printf("Aluno reprovado.");
    }
    
    return 0;
}
