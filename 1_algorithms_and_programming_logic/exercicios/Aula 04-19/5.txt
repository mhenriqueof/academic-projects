// Foi realizada uma pesquisa entre os habitantes de uma região ecoletados os dados de altura e sexo (0 = masc, 1 = fem, 2 = não declarado)das pessoas. Faça um programa que leia 50 dados diferentes e informe:● a maior e a menor altura encontradas;● a média de altura das mulheres;● a média de altura da população;● o percentual de homens na população

# include <stdio.h>

int main() {

    int sexo;
    float altura;
    
    float maior, menor, altura_mulheres = 0, altura_populacao = 0, cont_mulheres = 0, cont_homens = 0;

    for (int i = 1; i <= 5; i++) {
        
        printf("Dado %d\n", i);

        printf("Altura: ");
        scanf("%f", &altura);
        
        if (i == 1) {
            maior = altura;
            menor = altura;
        }
        
        if (altura > maior) {
            maior = altura;
        } else if (altura < menor) {
            menor = altura;
        }
        
        altura_populacao += altura;

        printf("Sexo [0 = masc | 1 = fem | 2 = não declarado]: ");
        scanf("%d", &sexo);
        
        switch (sexo) {
            case 0:
                cont_homens++;
                break;
            case 1:
                altura_mulheres += altura;
                cont_mulheres++;
                break;
            default:
                
        }

        printf("------------------------------------------------\n");

    }
    
    printf("Maior altura é %.2f e menor é %.2f\n", maior, menor);
    printf("Média altura das mulheres: %.2f\n", altura_mulheres / cont_mulheres);
    printf("Média de altura da população: %.2f\n", altura_populacao / 5);
    printf("Percentual de homens na população: %.2f%%", (float)cont_homens / 5 * 100);
    
    return 0;
}