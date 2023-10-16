#include <stdio.h>
#include  "lista1.h"
#include "lista.c"

int main() {
    No* lista = lista_criar();

    // Inserir caracteres na lista
  	lista_inserir_no_i(lista, 0, 'A');
    lista_inserir_no_i(lista, 1, 'B');
    lista_inserir_no_i(lista, 2, 'C');
    lista_inserir_no_i(lista, 3, 'D');
    lista_inserir_no_i(lista, 4, 'E');
    lista_inserir_no_i(lista, 5, 'A');
    lista_inserir_no_i(lista, 6, 'A');
    lista_inserir_no_i(lista, 7, 'B');
    lista_inserir_no_i(lista, 8, 'B');
    lista_inserir_no_i(lista, 9, 'E');

    // Verificar a existência de um caractere na lista
    char busca = 'C';
    int existe = lista_verificar_existencia(lista, busca);
    if (existe) {
        printf("O caractere '%c' existe na lista.\n", busca);
    } else {
        printf("O caractere '%c' nao existe na lista.\n", busca);
    }

    // Contar as ocorrências de um caractere na lista
    char busca2 = 'B';
    int ocorrencias = lista_verificar_ocorrencias(lista, busca2);
    printf("O caractere '%c' aparece %d vezes na lista.\n", busca2, ocorrencias);

    // Imprimir a lista na ordem inversa
    printf("Lista na Ordem Inversa: ");
    lista_imprimir_inversa(lista);
    printf("\n");

    // Remover um caractere da lista
    char caractere_a_remover = 'D';
    lista_remover_no(lista, caractere_a_remover);

    // Imprimir a lista após a remoção
    printf("Lista apos a remocao de '%c': ", caractere_a_remover);
    No* atual = lista->proximo;
    while (atual != NULL) {
        printf("%c ", atual->valor);
        atual = atual->proximo;
    }
    printf("\n");

    // Destruir a lista
    lista_destruir(lista);

    return 0;
}

