#include <stdio.h>
#include <stdlib.h>
	
//Contar a quantidade de ocorr�ncias de um elemento no array. Escreva uma fun��o que recebe um array de n�meros inteiros e um n�mero inteiro de busca, e retorna a quantidade de vezes que o n�mero de busca aparece no array.

int contarBusca(int array[], int tam, int numBusca){
	int i;
	int contador=0;
	
	for(i=0; i<tam; i++){
		if(array[i]==numBusca){
			contador++;
		
		}
	}
	return contador ;
}

	int main(){
		int tam=5 ;
		int numeros[]={20,40,30,20,21};
		int numBusca=20;
		int ocorrencias = contarBusca (numeros, tam, numBusca);
		int i ;
		
		printf("Array: ");
   		for ( i = 0; i < tam; i++) {
        printf(" \n %d \n", numeros[i]);	}
		printf(" o numero %d aparece %d vezes no array ", numBusca, ocorrencias);


		return 0;
		
	}

