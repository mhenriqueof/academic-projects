// Escreva um algoritmo que encontre o quinto número maior que1000 cuja divisão por 11 tenha resto 5

# include <stdio.h>

int main() {

    int number = 1000, cont = 0;

    while (1) {


        if (number % 11 == 5) {
            cont++;
        }
        
        if (cont == 5) {
            break;
        }

        printf("%d, %d\n", number, number % 11);
        number++;
    }
    printf("%d", number);

    return 0;
}
