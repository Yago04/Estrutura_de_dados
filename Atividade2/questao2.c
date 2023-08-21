#include <stdio.h>
#include <stdlib.h>


//- Maior e menor elemento do array. Escreva uma função que recebe um array de números inteiros e retorna o menor e o maior elemento do array.

int main(int argc, char *argv[]){
	int valor[4];
	int i;
	
		for(i=0; i<4; i++){
		
		printf("Por favor insira os valores: ", i+1);
		scanf("%d", &valor[i]);
	}
	
	
int  maior=valor[0];
	int menor=valor[0];
	
		
	for( i = 1; i<4; i++){
		
		if (valor[i] > maior){
			
			maior = valor[i];
			
		}
		
		if(valor[i] < menor){
		
			menor = valor[i];
		}
		
	}
		
		printf("o maior valor do array[%d]\n", maior );
			printf("o menor valor do array[%d]\n", menor );

	
	
	return 0;

}
