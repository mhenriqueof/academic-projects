# include <stdio.h>

int main() {

    int linhas = 3, colunas = 3, opcao;
    float matriz[linhas][colunas], soma = 0;

    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            printf("Valor para M(%d,%d): ", i+1, j+1);
            scanf("%f", &matriz[i][j]);
        }
    }

    printf("---\n");

    int flag = 1;

    while (flag) {

        printf("[1] Imprimir todos os elementos da matriz\n[2] Somar os quadrados de todos os elementos da primeira coluna\n[3] Somar todos os elementos da terceira linha\n[4] Somar os elementos da diagonal principal\n[5] Somar todos os elementos de índice par da segunda linha\n[0] Parar\n");

        scanf("%d", &opcao);
        printf("\n");

        switch (opcao) {

            case 0:
                flag = 0;
                break;

            case 1:

                for (int i = 0; i < linhas; i++) {
                    for (int j = 0; j < colunas; j++) {
                        printf("%.1f ", matriz[i][j]);
                    }
                    printf("\n");
                }
                break;

            case 2:

                for (int i = 0; i < linhas; i++) {
                    matriz[i][0] *= matriz[i][0];
                }
                break;

            case 3:

                for (int i = 0; i < linhas; i++) {
                    soma += matriz[2][i] ;
                }
                printf("%.1f\n", soma);
                break;

            case 4:

                for (int i = 0; i < linhas; i++) {
                    for (int j = 0; j < colunas; j++) {
                        if (i == j) {
                            soma += matriz[i][j];
                        }
                    }
                }
                printf("%.1f\n", soma);
                break;

            case 5:

                for (int i = 0; i < linhas; i++) {
                    if (i % 2 == 0) {
                        soma += matriz[1][i] ;
                    }
                }
                printf("%.1f\n", soma);
                break;

            default:
                printf("Valor invalido.");
                break;
        }
        printf("\n");
        soma = 0;
    }

    return 0;
}
