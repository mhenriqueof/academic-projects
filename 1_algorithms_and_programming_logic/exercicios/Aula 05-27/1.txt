# include <stdio.h>

void positive(float *value) {
    if (*value < 0) {
        *value *= -1;
    }
}

int main() {
    float number;

    printf("Number: ");
    scanf("%f", &number);

    positive(&number);

    printf("%.2f", number);

    return 0;
}
