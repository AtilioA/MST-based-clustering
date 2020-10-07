#include <stdlib.h>
#include <stdio.h>

#include "include/utils.h"
#include "include/union_find.h"
#include "include/point.h"

int main(int argc, char *argv[])
{
    // Teste de struct Point
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

    int nLinhas = count_lines(fp);
    printf("\n'%s' possui %i linhas.", fileIn, nLinhas);

    // Volta para o começo do arquivo
    rewind(fp);
    int ndimensions = determine_dimensions(fp);
    char *elements[nLinhas];
    double coordenates[M];
    printf("\nDimensões: %i\n", ndimensions);

    rewind(fp);
    read_input_file(fp, elements, coordenates);

    // fclose(fp);

    return 0;
}
