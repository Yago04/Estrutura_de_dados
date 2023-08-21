#include <stdio.h>
#include <string.h>

int buscaNoArray(const char *array[], int tamanho, const char *busca) {
	int i ;
    for ( i = 0; i < tamanho; i++) {
        if (strcmp(array[i], busca) == 0) {
            return 1; // Encontrado
        }
    }
    return 0; // Não encontrado
}

int main() {
    const char *array[] = {"melancia", "banana", "laranja", "uva"};
    const int tamanho = sizeof(array) / sizeof(array[0]);
    int i ;
    printf("Array:");
    for ( i = 0; i < tamanho; i++) {
    	
        printf(" %s", array[i]);
    }
    printf("\n");
    
    char busca[50];
    printf("Digite a string que deseja buscar: ");
    scanf("%s", busca);
    
    int resultado = buscaNoArray(array, tamanho, busca);
    
    if (resultado == 1) {
        printf("1.\n");
    } else {
        printf("0\n");
    }
    
    return 0;
}

