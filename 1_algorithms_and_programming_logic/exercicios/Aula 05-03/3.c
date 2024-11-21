# include <stdio.h>
# include <string.h>

int main() {
    
    char letra, string[200];
    int len, posicao = -1;
    
    printf("String: ");
    fgets(string, 200, stdin);
    
    len = strlen(string);
    
    printf("Caractere: ");
    scanf(" %c", &letra);
    
    for (int i = 0; i < len; i++) {
        
        if (letra == string[i]) {
            printf("%c - %c", letra, string[i]);
            posicao = i;
        }
    }
    
    if (posicao == -1) {
        printf("Nao houve ocorrencia da letra %c", letra);
    } else {
        printf("Posicao: %d", posicao);
    }

    return 0;
}
