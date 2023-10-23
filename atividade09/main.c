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

    // Vari�vel para calcular o tempo m�dio de inser��o
    clock_t inicio, fim;
    double tempo_total = 0.0;
    int total_insercoes = 0;

    // Leia n�meros do arquivo e insira nas listas
    float numero;
    while (fscanf(arquivo, "%f", &numero) == 1) {
        // Crie um n� para armazenar o n�mero
        No* no = (No*)malloc(sizeof(No));
        if (no == NULL) {
            perror("Erro na aloca��o de mem�ria para n�");
            exit(EXIT_FAILURE);
        }
        no->valor = numero;

        // Insira o n� na lista n�o ordenada
        inicio = clock();
        lista_inserir_no_i(lista_nao_ordenada, 0, no->valor); // Insira na posi��o 0 da lista n�o ordenada
        fim = clock();
        tempo_total += (double)(fim - inicio) / CLOCKS_PER_SEC;
        total_insercoes++;

        // Insira o n� na lista ordenada
        inicio = clock();
        lista_inserir_no_ordenado(lista_ordenada, no);
        fim = clock();
        tempo_total += (double)(fim - inicio) / CLOCKS_PER_SEC;
        total_insercoes++;
    }

    // Feche o arquivo
    fclose(arquivo);

    // Calcule o tempo m�dio de inser��o
    double tempo_medio = tempo_total / total_insercoes;
    printf("Tempo m�dio de inser��o: %lf segundos\n", tempo_medio);

    // Destrua as listas
    lista_destruir(lista_nao_ordenada);
    lista_destruir(lista_ordenada);

    return 0;
}

