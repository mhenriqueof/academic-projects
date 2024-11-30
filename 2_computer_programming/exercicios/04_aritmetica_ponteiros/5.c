# include <stdio.h>

void copiar(int tamanho, int *origem, int *destino) {

    for (int i = 0; i < tamanho; i++) {
        *(destino+i) = *(origem+i);
    }
}

int main() {

    int origem[] = {5,4,7,3,1};
    int tamanho = sizeof(origem) / sizeof(origem[0]);
    int destino[tamanho];

    copiar(tamanho, origem, destino);

    for (int i = 0; i < tamanho; i++) {
        printf("%d ", destino[i]);
    }
    
    return 0;
}
