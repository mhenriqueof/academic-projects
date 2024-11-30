# include <stdio.h>

void trocar(int *p1, int *p2) {

    int temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

int main() {

    int n1 = 1, n2 = 2;
    int *p1 = &n1, *p2 = &n2;

    printf("Before: %d - %d\n", n1, n2);

    trocar(p1, p2);

    printf("After: %d - %d", n1, n2);

    return 0;
}
