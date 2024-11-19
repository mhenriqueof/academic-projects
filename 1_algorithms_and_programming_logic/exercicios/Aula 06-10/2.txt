#include <stdio.h>

typedef struct {
    char data[8];
    char time_man[20];
    char time_vis[20];
    int gols_man;
    int gols_vis;
} jogos;

int main() {
    
    int tamanho = 2;
    jogos jogo[tamanho];
    
    for (int i = 0; i < tamanho; i++) {
        
        fflush(stdin);
        printf("Data do jogo: ");
        scanf("%s", jogo[i].data);

        fflush(stdin);
        printf("Time mandante: ");
        scanf("%s", jogo[i].time_man);

        fflush(stdin);
        printf("Time visitante: ");
        scanf("%s", jogo[i].time_vis);
        
        printf("Gols do mandante: ");
        scanf("%d", &jogo[i].gols_man);
        
        printf("Gols do visitante: ");
        scanf("%d", &jogo[i].gols_vis);
        
        printf("O entre %s x %s jogado no dia %s. ")
        if (jogo[i].gols_man == jogo[i].gols_vis) {
            printf("Deu empate.")
        } else if (jogo[i].gols_man > jogo[i].gols_vis) {
            printf("Teve o time %s como vencedor.", jogo[i].time_man);
        } else {
            printf("Teve o time %s como vencedor.", jogo[i].time_vis);
        }
        
    }
    
    
    
    return 0;
}
