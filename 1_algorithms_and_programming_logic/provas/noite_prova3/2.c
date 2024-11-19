# include <stdio.h>
# include <string.h>
# include <stdlib.h>

int main() {

    char vetor_a[100], vetor_b[100];
    int i, j, cont = 0;
    
    printf("Valor para A [maior que zero e menor que 100 digitos]: ");
    fgets(vetor_a, 100, stdin);
    	
    printf("Valor para B [maior que zero e menor que 100 digitos]: ");
    fgets(vetor_b ,100, stdin);
    	
    printf("%s", vetor_a);
    printf("%s", vetor_b);
    
    printf("---\n");
    
    for (i = strlen(vetor_a)-2, j = strlen(vetor_b)-2; j >= 0; i--, j--) {
    	
    	if (vetor_a[i] == vetor_b[j]) {
    		cont++;
		}
	}
	
	if (cont == strlen(vetor_b)-1) {
		printf("encaixa");
	} else {
		printf("nao encaixa");
	}
    	   
    return 0;
}

