#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <locale.h>
#include "fila.h"
#include "fila.c"
#include "pilha.h"
#include "pilha.c"
int main() {
    setlocale(LC_ALL, "Portuguese");
    int novo = 1;

    while (novo) {
        printf("Digite a sequencia de nucleotideos(digite apenas as letras A, C, T ou G):");
        char dna[100];
        scanf("%s", dna);

        int len = strlen(dna);
        dna[len] = '\0';

        Fila* fila = criarFila();

        int i;
        for (i = 0; i < len; i++) {
            char nucleotideo = toupper(dna[i]);

            if (nucleotideo != 'A' && nucleotideo != 'C' && nucleotideo != 'T' && nucleotideo != 'G') {
                printf("\nLetra invalida! Por favor, digite apenas as letras A, C, T ou G.\n\n");
                break;
            }

            enfileirar(fila, nucleotideo);

            if (i == len - 1) {
                novo = 0;
            }
        }

        if (novo) {
            free(fila);
            continue;
        }

        Pilha* pilha = criarPilha();

        printf("Fila: ");
        imprimirFila(fila);

        while (!filaVazia(fila)) {
            char nucleotideo = fila->inicio->nucleotideo;
            desenfileirar(fila);

            switch (nucleotideo) {
                case 'A':
                    nucleotideo = 'A';
                    break;
                case 'T':
                    nucleotideo = 'T';
                    break;
                case 'C':
                    nucleotideo = 'C';
                    break;
                case 'G':
                    nucleotideo = 'G';
                    break;
            }

            empilhar(pilha, nucleotideo);
        }

        printf("Pilha: ");
        imprimirPilha(pilha);

        free(fila);
        free(pilha);
    }

	return 0;
}
