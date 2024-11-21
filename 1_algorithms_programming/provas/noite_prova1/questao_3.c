# include <stdio.h>

int main() {

    int saque;
    
    printf("Valor do saque: ");
    scanf("%d", &saque);

    if (saque >= 200) {
        printf("%d cedulas 200\n", saque/200);
        saque = saque % 200;
    }
    if (saque >= 100) {
        printf("%d cedulas 100\n", saque/100);
        saque = saque % 100;
    }
    if (saque >= 50) {
        printf("%d cedulas 50\n", saque/50);
        saque = saque % 50;
    }
    if (saque >= 20) {
        printf("%d cedulas 20\n", saque/20);
        saque = saque % 20;
    }
    if (saque >= 10) {
        printf("%d cedulas 10\n", saque/10);
        saque = saque % 10;
    }
    if (saque >= 5) {
        printf("%d cedulas 5\n", saque/5);
        saque = saque % 5;
    }
    if (saque >= 1) {
        printf("%d moedas 1\n", saque/1);
        saque = saque % 1;
    }

    return 0;
}
