#include <stdlib.h>
#include <stdio.h>

#include "include/utils.h"
#include "include/union_find.h"
#include "include/point.h"
#include "include/dists.h"
// #include "include/kruskal.h"

int main(int argc, char *argv[])
{
    if (argc < 3)
    {
        return EXIT_FAILURE;
    }

    // Salva nome do arquivo de entrada dos argumentos
    char *fileIn = argv[1];
    // Salva quantidade de grupos
    int k = atoi(argv[2]);
    // Salva nome do arquivo de saída
    char *fileOut = argv[3];

    // Abre arquivo de entrada
    FILE *fpIn = fopen(fileIn, "r");

    if (!fpIn)
    {
        fprintf(stderr, "Falha ao abrir o arquivo '%s'.\n", fileIn);
        return -1;
    }

    printf("\nLendo arquivo de entrada...\n");
    int nLines = count_lines(fpIn);
    printf("'%s' possui %i linhas.", fileIn, nLines);

    // Volta para o começo do arquivo
    rewind(fpIn);
    int nDimensions = determine_dimensions(fpIn);
    printf("\nDimensões: %i\n", nDimensions);

    char *linesIDs[nLines];
    double pointsVectorizedMatrix[nDimensions * nLines];

    rewind(fpIn);
    read_input_file(fpIn, linesIDs, pointsVectorizedMatrix);
    printf("Fim da leitura do arquivo de entrada.\n\n");
    fclose(fpIn);

    Point **points_array;
    points_array = Point_array_init(linesIDs, pointsVectorizedMatrix, nLines, nDimensions);

    printf("Calculando distâncias...\n");
    Dist *distArray = Dist_create_array(points_array, nLines, nDimensions);

    printf("Ordenando distâncias...\n");
    distArray = Dist_sort(distArray, nLines);

    printf("Gerando árvore geradora mínima...\n");
    UF *MST = generate_MST_kruskal(distArray, points_array, nLines, linesIDs, k);

    points_array = Point_sort(points_array, nLines, MST);

    // Ordenar vetor de pontos em ordem alfabética com strcmp e qsort
    // Escrever grupos já ordenados alfabeticamente num arquivo de saída obtido no argv

    Point_print_array(points_array, nLines, nDimensions);
    // Dist_print_array(distArray, nLines);
    UF_print(MST, points_array);

    // Abre arquivo de entrada
    FILE *fpOut = fopen(fileOut, "w");

    if (!fpOut)
    {
        fprintf(stderr, "Falha ao abrir o arquivo '%s'.\n", fileIn);
        return -1;
    }

    write_output_file(fpOut, points_array, MST);

    fclose(fpOut);

    // Libera estruturas da memória
    for (int i = 0; i < nLines; i++)
    {
        free(linesIDs[i]);
    }
    Point_free_array(points_array, nLines);
    free(distArray);
    UF_free(MST);

    return 0;
}
