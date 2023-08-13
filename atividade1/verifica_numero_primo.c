#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {

int num, i, resultado = 0;
 
 printf("Digite um numero: ");
 scanf("%d", &num);
 
 for (i = 2; i <= num / 2; i++) {
    if (num % i == 0) {
       resultado++;
       break;
    }
 }
 
 if (resultado == 0)
    printf("1");
 else
    printf("0");
    
	return 0;
}