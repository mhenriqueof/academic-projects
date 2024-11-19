// Escreva um programa que mostra na tela todos os númerosinteiros divisíveis por 7 contidos no intervalo fechado [0, 1000]

# include <stdio.h>

int main() {
    for (int i = 0; i <= 1000; i++) {

        if (i % 7 == 0) {
            printf("%d | ", i);
        }
    }
}
