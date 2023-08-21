#include <stdio.h>

int main() {
    int tamanho;
    printf("Digite o tamanho dos vetores: ");
    scanf("%d", &tamanho);

    int vetor_a[tamanho];
    int vetor_b[tamanho];
    int vetor_c[tamanho];
	int i ;
    // Preenchendo o vetor A com os valores digitados pelo usuário
    for ( i = 0; i < tamanho; i++) {
        printf("\nDigite o valor %d do vetor A: ", i + 1);
        scanf("%d", &vetor_a[i]);
    }
    
    
        for ( i = 0; i < tamanho; i++) {
        printf("\nDigite o valor %d do vetor b: ", i + 1);
        scanf("%d", &vetor_b[i]);
    }


  
    for ( i = 0; i < tamanho; i++) {
        vetor_c[i] = vetor_a[i] * vetor_b[i] ;
    }


    printf("Vetor A: ");
    for ( i = 0; i < tamanho; i++) {
        printf("|%d|", vetor_a[i]);
    }
    printf("\n");

    printf("\nVetor B: ");
    for ( i = 0; i < tamanho; i++) {
        printf("|%d|", vetor_b[i]);
    }
    printf("\n");


	 printf("\nVetor C : ");
    for ( i = 0; i < tamanho; i++) {
        printf("|%d|", vetor_c[i]);
    }

    return 0;
}
