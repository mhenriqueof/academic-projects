# include <stdio.h>

int main() {

    int *p1, *p2;

    if (&p1 > &p2) {
        printf("%ld > %ld", &p1, &p2);
    } else {
        printf("%ld > %ld", &p2, &p1);
    }

    return 0;
}


