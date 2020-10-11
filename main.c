#include <stdlib.h>
#include <stdio.h>

#include "include/utils.h"
#include "include/union_find.h"
#include "include/point.h"
#include "include/dists.h"

int main(int argc, char *argv[])
{
    // Salva nome do arquivo de entrada dos argumentos
    char *fileIn = argv[1];
    // Salva quantidade de grupos
    // int k = atoi(argv[2]);
    // Salva nome do arquivo de saída
    // char *fileOut = argv[3];
    // int nDimensions;

    // Abre arquivo de entrada
    FILE *fp = fopen(fileIn, "r");

    if (!fp)
    {
        fprintf(stderr, "Falha ao abrir o arquivo '%s'.\n", fileIn);
        return -1;
    }

    int nLines = count_lines(fp);
    printf("\n'%s' possui %i linhas.", fileIn, nLines);

    // Volta para o começo do arquivo
    rewind(fp);
    int nDimensions = determine_dimensions(fp);
    printf("\nDimensões: %i\n", nDimensions);

    char *linesIDs[nLines];
    double pointsVectorizedMatrix[nDimensions * nLines];

    rewind(fp);
    read_input_file(fp, linesIDs, pointsVectorizedMatrix);

    Point **points_array;

    points_array = Point_array_init(linesIDs, pointsVectorizedMatrix, nLines, nDimensions);

    Point_print_array(points_array, nLines, nDimensions);

    Dist *distArray = Dist_create_array(points_array, nLines, nDimensions);

    distArray = Dist_sort(distArray, nLines);

    // Rodar algoritmo de Kruskal com distArray

    // Remover k - 1 arestas restantes

    // Criar lista de grupos e/ou grupos que serão listas contendo nós do UF

    // Ordenar grupo internamente em ordem alfabética com strcmp

    // Ordenar grupos por ordem alfabética com strcmp

    // Escrever grupos em ordem alfabética num arquivo de saída obtido no argv

    Dist_print_array(distArray, nLines);

    fclose(fp);

    // Libera estruturas da memória
    for (int i = 0; i < nLines; i++)
    {
        free(linesIDs[i]);
    }
    Point_free_array(points_array, nLines);
    free(distArray);

    return 0;
}
