// Quico tem 1,40 metro e cresce 2 centímetros por ano, enquanto Chaves tem 1,10 metro e cresce 3centímetros por ano. Construa um algoritmo que calcule e imprima quantos anos serão necessáriospara que Chaves seja maior que Quico

# include <stdio.h>

int main() {
	
	int anos = 0;
	float quico = 1.4;
	float chaves = 1.10;
	
	while (quico > chaves) {
		
		quico = quico + 0.02;
		chaves = chaves + 0.03;
		anos++;
		
	}
	
	printf("%d anos", anos);
}
