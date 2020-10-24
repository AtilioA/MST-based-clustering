#include <stdlib.h>
#include <stdio.h>
#include <time.h>

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

    // Guarda nome do arquivo de entrada dos argumentos
    char *fileIn = argv[1];
    // Guarda quantidade de grupos
    int k = atoi(argv[2]);
    // Guarda nome do arquivo de saída
    char *fileOut = argv[3];

    // Começo da leitura dos dados
    clock_t clocksRead = clock();

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
    printf("Fim da leitura do arquivo de entrada.\n");
    fclose(fpIn);

    clocksRead = clock() - clocksRead;
    // Fim da leitura dos dados

    double timeTakenRead = ((double)clocksRead) / CLOCKS_PER_SEC;

    Point **points_array;
    points_array = Point_array_init(linesIDs, pointsVectorizedMatrix, nLines, nDimensions);

    // Começo do cálculo das distâncias
    clock_t clocksCalcDist = clock();

    printf("\nCalculando distâncias...\n");
    Dist *distArray = Dist_create_array(points_array, nLines, nDimensions);
    // Fim do cálculo das distâncias

    clocksCalcDist = clock() - clocksCalcDist;
    double timeTakenCalcDist = ((double)clocksCalcDist) / CLOCKS_PER_SEC;

    // Começo da ordenação das distâncias
    clock_t clocksSortDist = clock();

    printf("Ordenando distâncias...\n");
    distArray = Dist_sort(distArray, nLines);
    // Fim da ordenação das distâncias

    clocksSortDist = clock() - clocksSortDist;
    double timeTakenSortDist = ((double)clocksSortDist) / CLOCKS_PER_SEC;

    // Começo da obtenção da MST
    clock_t clocksMST = clock();

    printf("\nGerando árvore geradora mínima...\n");
    UF *MST = generate_MST_kruskal(distArray, nLines, linesIDs, k);

    clocksMST = clock() - clocksMST;
    double timeTakenMST = ((double)clocksMST) / CLOCKS_PER_SEC;
    // Fim da obtenção da MST

    // Começo da identificação dos grupos
    clock_t clocksIDGroups = clock();

    printf("Identificando grupos...\n");
    points_array = Point_sort(points_array, nLines, MST);

    points_array = Point_group_sort(points_array, nLines, MST);
    clocksIDGroups = clock() - clocksIDGroups;
    double timeTakenIDGroups = ((double)clocksIDGroups) / CLOCKS_PER_SEC;
    // Fim da identificação dos grupos

    // Ordenar vetor de pontos em ordem alfabética com strcmp e qsort

    // Point_print_array(points_array, nLines, nDimensions);
    // Dist_print_array(distArray, nLines);
    // UF_print(MST, points_array);

    // Começo da escrita dos dados
    clock_t clocksWrite = clock();

    // Abre arquivo de saída
    FILE *fpOut = fopen(fileOut, "w");

    if (!fpOut)
    {
        fprintf(stderr, "\nFalha ao abrir o arquivo '%s'.\n", fileOut);
        return -1;
    }

    // Escreve grupos no arquivo de saída
    printf("\nEscrevendo grupos em '%s'...\n", fileOut);
    write_output_file(fpOut, points_array, MST);

    fclose(fpOut);

    clocksWrite = clock() - clocksWrite;
    double timeTakenWrite = ((double)clocksWrite) / CLOCKS_PER_SEC;
    // Fim da escrita dos dados

    printf("Liberando estruturas da memória...\n");
    // Libera estruturas da memória
    for (int i = 0; i < nLines; i++)
    {
        free(linesIDs[i]);
    }
    Point_free_array(points_array, nLines);
    free(distArray);
    UF_free(MST);

    printf("\nFim.\n");

    printf("\n======= TEMPOS %s =======\n", fileIn);
    printf("%-27s %lfs\n", "Leitura:", timeTakenRead);
    printf("%-29s %lfs\n", "Cálculo de distâncias:", timeTakenCalcDist);
    printf("%-30s %lfs\n", "Ordenação de distâncias:", timeTakenSortDist);
    printf("%-29s %lfs\n", "Identificação de grupos:", timeTakenIDGroups);
    printf("%-29s %lfs\n", "Obtenção da MST:", timeTakenMST);
    printf("%-27s %lfs\n", "Escrita:", timeTakenWrite);

    return EXIT_SUCCESS;
}
