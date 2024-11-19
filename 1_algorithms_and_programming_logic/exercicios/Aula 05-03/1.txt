# include <stdio.h>
# include <string.h>

int main() {
    
    char string[200];
    int len;
    
    printf("String: ");
    fgets(string, 200, stdin);
    
    printf("%s\n", string);
    
    len = strlen(string);
    
    for (int i = len-1; i >= 0; i--) {
        printf("%c", string[i]);
    }

    return 0;
}
