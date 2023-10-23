#include "lista.h"
#include "lista.c"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Crie as duas listas: lista_nao_ordenada e lista_ordenada
    No* lista_nao_ordenada = lista_criar();
    No* lista_ordenada = lista_criar();

    // Abra o arquivo para leitura
    FILE* arquivo = fopen("1kk_rand_float.csv", "r");
    if (arquivo == NULL) {
        perror("Erro ao abrir o arquivo");
        exit(EXIT_FAILURE);
    }

    // Variável para calcular o tempo médio de inserção
    clock_t inicio, fim;
    double tempo_total = 0.0;
    int total_insercoes = 0;

    // Leia números do arquivo e insira nas listas
    float numero;
    while (fscanf(arquivo, "%f", &numero) == 1) {
        // Crie um nó para armazenar o número
        No* no = (No*)malloc(sizeof(No));
        if (no == NULL) {
            perror("Erro na alocação de memória para nó");
            exit(EXIT_FAILURE);
        }
        no->valor = numero;

        // Insira o nó na lista não ordenada
        inicio = clock();
        lista_inserir_no_i(lista_nao_ordenada, 0, no->valor); // Insira na posição 0 da lista não ordenada
        fim = clock();
        tempo_total += (double)(fim - inicio) / CLOCKS_PER_SEC;
        total_insercoes++;

        // Insira o nó na lista ordenada
        inicio = clock();
        lista_inserir_no_ordenado(lista_ordenada, no);
        fim = clock();
        tempo_total += (double)(fim - inicio) / CLOCKS_PER_SEC;
        total_insercoes++;
    }

    // Feche o arquivo
    fclose(arquivo);

    // Calcule o tempo médio de inserção
    double tempo_medio = tempo_total / total_insercoes;
    printf("Tempo médio de inserção: %lf segundos\n", tempo_medio);

    // Destrua as listas
    lista_destruir(lista_nao_ordenada);
    lista_destruir(lista_ordenada);

    return 0;
}

