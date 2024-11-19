# include <stdio.h>

int cont = 0;

float scan() {
    float nota;
    printf("Nota %d: ", cont+1);
    cont++;
    scanf("%f", &nota);
    return nota;
}

void media(float n1, float n2, float n3) {
    
    int peso1 = 2, peso2 = 3, peso3 = 5;
    int peso_total = peso1 + peso2 + peso3;

    printf("%.2f", (n1 * peso1 + n2 * peso2 + n3 * peso3) / peso_total);
}

int main() {

    float n1 = scan(), n2 = scan(), n3 = scan();

    printf("\n%d\n", cont);

    media(n1, n2, n3);
}
