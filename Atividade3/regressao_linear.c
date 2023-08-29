#include <stdio.h>
#include <stdlib.h>

typedef struct {
    double x;
    double y;
} Ponto;

int main(int argc, int i, char *argv[]) {
    if (argc != 2) {
        printf("Uso: %s <dados.csv>\n", argv[0]);
        return 1;
    }

 	FILE * dados.cvs= fopen(argv[1], "C:\Users\Yago Ribeiro\Desktop\faculdade\Estrutura de dados\dados.csv", "r");
    if (arquivo == NULL) {
        printf("Não foi possível abrir o arquivo %s\n", argv[1]);
        return 1;
    }

    // Contar a quantidade de registros no arquivo
    int numRegistros = 0;
    char linha[100];
    while (fgets(linha, sizeof(linha), arquivo) != NULL) {
        numRegistros++;
    }

    // Alocar dinamicamente o array de pontos
    Ponto *pontos = (Ponto *)malloc(numRegistros * sizeof(Ponto));

    // Voltar para o início do arquivo
    rewind(arquivo);

    // Ler os pontos do arquivo e calcular a média de x e y
    double somaX = 0.0, somaY = 0.0;

    for ( i = 0; i < numRegistros; i++) {
        fscanf(arquivo, "%lf,%lf", &pontos[i].x, &pontos[i].y);
        somaX += pontos[i].x;
        somaY += pontos[i].y;
    }

    double mediaX = somaX / numRegistros;
    double mediaY = somaY / numRegistros;

    // Calcular a inclinação da reta de regressão (coeficiente angular)
    double numerador = 0.0, denominador = 0.0;
   
    for ( i = 0; i < numRegistros; i++) {
        numerador += (pontos[i].x - mediaX) * (pontos[i].y - mediaY);
        denominador += (pontos[i].x - mediaX) * (pontos[i].x - mediaX);
    }
    double coeficienteAngular = numerador / denominador;

    printf("Coeficiente Angular (Inclinação da Reta de Regressão): %.4lf\n", coeficienteAngular);

    // Liberar a memória alocada
    free(pontos);
    fclose(arquivo);

    return 0;
}

