# include <stdio.h>

int main() {

    int i=34, j; 
    int *p;

    p = &i;
    *p++;
    j = *p + 33;

    printf("i - %d\nj - %d\np - %d\n", i, j, *p);
    printf("%d", &p);
}
