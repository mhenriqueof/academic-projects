# include <stdio.h>

int main() {

    int i=7, j=5, c;
    int *p;
    int **q;
    
    p = &i;
    q = &p;
    c = **q + j;
    printf("%d\n", c);

    **q = 20;

    printf("%d", c);

    return 0;    
}
