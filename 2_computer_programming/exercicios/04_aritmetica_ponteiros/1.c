# include <stdio.h>

int main() {

    int n1 = 1, n2 = 2, n3 = 3;
    
    int *p = &n1;
    printf("%d\n", *p);

    p = &n2;
    printf("%d\n", *p);

    p = &n3;
    printf("%d", *p);

    return 0;
}
