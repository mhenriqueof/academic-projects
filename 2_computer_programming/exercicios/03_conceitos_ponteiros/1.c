# include <stdio.h>

void pointer() {
    int x = 10;
    int y = 2;
    int *p;

    p = &x;
    y = *p;
    *p = 0;

    printf("%d - %d - %d", x, y, *p); // 0
}

int main() {

    pointer();

    return 0;
}
