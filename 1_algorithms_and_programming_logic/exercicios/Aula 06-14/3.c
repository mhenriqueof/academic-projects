# include <stdio.h>

typedef struct {
    char modelo[20];
    int ano;
    float valor;
    char placa[10];
    int renavam;
    float ipva;
} carros;

int main() {
    
    int tamanho = 2, combustivel;
    carros carro[tamanho];

    for (int i = 0; i < tamanho; i++) {
        printf("--- Carro %d ---\n", i+1);

        fflush(stdin);
        printf("Modelo: ");
        scanf("%[^\n]s", carro[i].modelo);

        printf("Ano: ");
        scanf("%d", &carro[i].ano);

        printf("Valor: ");
        scanf("%f", &carro[i].valor);

        fflush(stdin);
        printf("Placa: ");
        scanf("%[^\n]s", carro[i].placa);

        printf("RENAVAM: ");
        scanf("%d", &carro[i].renavam);

        if (2024 - carro[i].ano > 20) {
            carro[i].ipva = 0;
        } else {
            printf("Tipo combustivel\n[1] gas\n[2] flex\n[3] gasolina\n");
            scanf("%d", &combustivel);
            switch (combustivel) {
                case 1:
                    carro[i].ipva = carro[i].valor * 0.01;
                    break;
                case 2:
                    carro[i].ipva = carro[i].valor * 0.02;
                    break;
                case 3:
                    carro[i].ipva = carro[i].valor * 0.04;
                    break;
                default:
                    printf("Valor invalido.");
            }
        }
    }

    for (int i = 0; i < tamanho; i++) {
        printf("--- Carro %d ---\n", i+1);
        
        printf("Modelo: %s\nPlaca: %s\nRENAVAM: %d\nIPVA: %.2f\n", carro[i].modelo, carro[i].placa, carro[i].renavam, carro[i].ipva);

        printf("\n");
    }
}
