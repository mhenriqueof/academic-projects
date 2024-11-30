# include <stdio.h>

int main() {

    int a=5, b=12, c=5;
    int *p;
    int *q;

    p = &a;
    q = &b;
    (*p)++;
    c = *p + *q;

    printf("a: %d\nb: %d\nc: %d\np: %ld\nq: %ld", a, b, c, (long int) p, (long int) q);

    return 0;
}