# include <stdio.h>

int mod(int x, int y) {

    if (x > y) {
        return mod(x-y, y);
    } else if (x < y) {
        return x;
    } else {
        return 0;
    }
}

int main() {

    int x = 5, y = 5;

    printf("Resultado: %d", mod(x,y));

    return 0;
}
