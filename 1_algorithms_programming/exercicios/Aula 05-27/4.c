# include <stdio.h>

void mostrar_menu() {
    printf("\
[1] Pao R$ 9,90\n\
[2] Abacate R$ 1,50\n\
[3] Peito de frango R$ 0,99\n\
[4] Cortador de unha R$ 99,98\n\
[5] Cimento R$ 20,00\n\
[0] Finalizar pedido.\n");
}

void escolher(float *total, int *flag) {

    int opcao;

    printf("Escolha um produto: ");
    scanf("%d", &opcao);

    switch (opcao) {
        case 0:
            *flag = 0;  
            break;  
        case 1:
            *total += 9.9;  
            break;  
        case 2:
            *total += 1.5;  
            break;  
        case 3:
            *total += 0.99;  
            break;  
        case 4:
            *total += 99.98;  
            break;  
        case 5:
            *total += 20.0;  
            break;  
        default:
            printf("Valor invalido.\n");  
            break; 
    };
    printf("Total: %.2f\n\n", *total); 
}

int main() {

    float valor = 0;
    int flag = 1;

    printf("| Padaria no ceu tem pao |\n--- Menu ---\n");
    while (flag == 1) {
        mostrar_menu();
        escolher(&valor, &flag);
    };

    return 0;
}
