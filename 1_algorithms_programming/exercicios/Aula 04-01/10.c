// A fabricação dos presentes para o Natal é um processo muitocomplicado. Diversas vezes os duendes ficam até tarde trabalhando para quetudo possa ser terminado a tempo e com perfeição. Para melhor gerenciarseus cronogramas, os duendes estipularam quantos minutos são necessáriospara fabricar cada presente. Já está quase no final do expediente, e um dosduendes pediu sua ajuda. Faltam N minutos para a hora de ir embora, e restamdois presentes para o duende Ed fabricar. Ajude-o a descobrir se eleconseguirá fabricar os dois ainda hoje, ou se deve deixar o trabalho paraamanhã

#include <stdio.h>

int main() {
    
    int N, A, B;
    
    printf("Minutos faltantes: ");
    scanf("%d", &N);
    
    printf("Minutos necessários para o presente A: ");
    scanf("%d", &A);
    
    printf("Minutos necessários para o presente B: ");
    scanf("%d", &B);
    
    if (N >= A + B) {
        printf("Farei hoje!");
    } else {
        printf("Deixa para amanha!");
    }

    return 0;
}
