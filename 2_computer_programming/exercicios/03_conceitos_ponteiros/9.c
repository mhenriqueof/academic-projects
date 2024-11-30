# include <stdio.h>

int main() {

    int inteiro = 2;
    float real = 9.9;
    char caractere = 'a';

    printf("%d\n", inteiro);
    printf("%f\n", real);
    printf("%c\n", caractere);

    int *p_inteiro = &inteiro;
    float *p_real = &real;
    char *p_caractere = &caractere;

    *p_inteiro = 10;
    *p_real = 1.0;
    *p_caractere = 'z';

    printf("\n");

    printf("%d\n", inteiro);
    printf("%f\n", real);
    printf("%c\n", caractere);

    return 0;
}
