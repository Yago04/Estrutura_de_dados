#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void bubbleSort(char **array, int n) {
    int swapped;
    char *temp;

    do {
        swapped = 0;
        for (int i = 1; i < n; i++) {
            if (strcmp(array[i - 1], array[i]) > 0) {
                // Troca as palavras
                temp = array[i - 1];
                array[i - 1] = array[i];
                array[i] = temp;
                swapped = 1;
            }
        }
    } while (swapped);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Uso: %s arquivo_de_entrada.txt\n", argv[0]);
        return 1;
    }

    FILE *inputFile = fopen(argv[1], "r");
    if (inputFile == NULL) {
        perror("Erro ao abrir o arquivo de entrada");
        return 1;
    }

    // Lê as palavras do arquivo
    char *words[1000];  // Assumindo que não há mais de 1000 palavras
    int numWords = 0;

    char buffer[100];
    while (fgets(buffer, sizeof(buffer), inputFile) != NULL) {
        // Remove a quebra de linha, se presente
        buffer[strcspn(buffer, "\n")] = '\0';
        words[numWords] = strdup(buffer);
        numWords++;
    }

    fclose(inputFile);

    // Ordena as palavras
    bubbleSort(words, numWords);

    // Cria um novo arquivo com as palavras ordenadas
    FILE *outputFile = fopen("arq_palavras_ordenado.txt", "w");
    if (outputFile == NULL) {
        perror("Erro ao criar o arquivo de saída");
        return 1;
    }

    for (int i = 0; i < numWords; i++) {
        fprintf(outputFile, "%s\n", words[i]);
        free(words[i]);
    }

    fclose(outputFile);

    printf("Palavras ordenadas com sucesso em 'arq_palavras_ordenado.txt'\n");

    return 0;
}

