#ifndef LISTA_H
#define LISTA_H

typedef struct No {
    float valor;  // Modificado para armazenar valores FLOAT
    struct No* proximo;
} No;

No* lista_criar();
void lista_destruir(No* L);
void lista_inserir_no_ordenado(No* L, No* no); // Função adicionada
void lista_inserir_no_i(No* L, int i, float novo_valor); // Função de inserção modificada para FLOAT
void lista_remover_no_i(No* L, int i);
void lista_remover_no(No* L, float valor_busca); // Função de remoção modificada para FLOAT

#endif