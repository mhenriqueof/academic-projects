# include <stdio.h>
# include <string.h>

int main() {
    
    char letra, string[200];
    int len, posicao = -1;
    int a = 0, e = 0, i = 0, o = 0, u = 0;
    
    printf("String: ");
    fgets(string, 200, stdin);
    
    len = strlen(string);
    
    for (int i = 0; i < len; i++) {
        
        // printf("%c", string[i]);
        
        if (string[i] == 'a' || string[i] == 'A') {
            a += 1;
        } else if (string[i] == 'e' || string[i] == 'E') {
            e += 1;
        } else if (string[i] == 'i' || string[i] == 'I') {
            i += 1;
        } else if (string[i] == 'o' || string[i] == 'O') {
            o += 1;
        } else if (string[i] == 'u' || string[i] == 'U') {
            u += 1;
        }
    }
    
    printf("Ocorrencia das vogais:\na: %d\ne: %d\ni: %d\no: %d\nu: %d", a, e, i, o, u);

    return 0;
}
