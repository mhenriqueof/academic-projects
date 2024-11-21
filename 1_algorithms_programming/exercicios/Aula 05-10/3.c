# include <stdio.h>
# include <string.h>

int main() {


    char string[] = "ana banana";
    int pos = 0;
    
    // printf("%s", string);

    for (int i = strlen(string); i >= 0; i--) {
        // printf("%c", string[i]);

        printf("%c e %c", string[pos], string[i-1]);
        printf("\n");

        if (string[pos] != string[i-1]) {
            pos = 0;
            break;
        }
        pos++;
    }

    if (pos == 0) {
        printf("Nao e palindromo.");
    } else {
        printf("E palindromo.");
    }

    return 0;
}
