# include <stdio.h>

int main() {

    int *pti;
    int i = 10;
    pti = &i;

    *pti = 20;
    printf("%d", i);
}
