#include <stdlib.h>
#include <stdio.h>

#include "include/utils.h"
#include "include/union_find.h"
#include "include/point.h"
#include "include/dists.h"

int main(int argc, char *argv[])
{
    /* Teste de struct Point
    static int M = 5;
    double ponto[M];
    for (int i = 0; i < M; i++)
    {
        ponto[i] = i + 1;
        // printf("%i ", ponto[i]);
    }

    char *testeNome = "Hello, World";
    Point *teste = Point_init(testeNome, ponto, 5);
    printf("meu nome: %s", Point_get_name(teste));
    for (int i = 0; i < M; i++)
    {
        printf("\n%i ", Point_get_coordinates(teste)[i]);
    }
    */

    // Salva nome do arquivo de entrada dos argumentos
    char *fileIn = argv[1];
    // // Salva quantidade de grupos
    // int k = atoi(argv[2]);
    // // Salva nome do arquivo de saída
    // char *fileOut = argv[3];
    // int nDimensions;

    // // Abre arquivo de entrada
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

    Point **points_vector;

    points_vector = Point_vector_init(linesIDs, pointsVectorizedMatrix, nLines, nDimensions);

    print_points(points_vector, nLines, nDimensions);

    Dist *distArray = create_distance_array(points_vector, nLines, nDimensions);

    distArray = dist_sort(distArray, nLines);

    print_distances(distArray, nLines);

    fclose(fp);

    for (int i = 0; i < nLines; i++)
    {
        free(linesIDs[i]);
    }
    Point_vector_free(points_vector, nLines);
    free(distArray);

    return 0;
}
