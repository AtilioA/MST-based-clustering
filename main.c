#include <stdlib.h>
#include <stdio.h>

#include "include/utils.h"
#include "include/union_find.h"
#include "include/point.h"

int main(/*int argc, char *argv[]*/)
{
    // Teste de struct Point
    static int M = 5;
    int ponto[M];
    for (int i = 0; i < M; i++)
    {
        ponto[i] = i + 1;
        printf("%i ", ponto[i]);
    }

    char *testeNome = "Hello, World";
    // Segfault no init
    Point *teste = Point_init(testeNome, ponto, 5);
    printf("%s", Point_get_name(teste));
    // Salva nome do arquivo de entrada dos argumentos
    // char *fileIn = argv[1];
    // // Salva quantidade de grupos
    // int k = atoi(argv[2]);
    // // Salva nome do arquivo de saída
    // char *fileOut = argv[3];
    // int nDimensions;

    // // Abre arquivo de entrada
    // FILE *fp = fopen(fileIn, "r");

    // if (!fp)
    // {
    //     fprintf(stderr, "Falha ao abrir o arquivo '%s'.\n", fileIn);
    //     return -1;
    // }

    // int nLinhas = count_lines(fp);
    // printf("\n'%s' possui %i linhas.", fileIn, nLinhas);

    // // Volta para o começo do arquivo
    // rewind(fp);
    // nDimensions = determine_dimensions(fp);
    // printf("\nDimensões: %i\n", nDimensions);

    // /*
    // rewind(fp);
    // read_input_file(fp);
    // */

    // fclose(fp);

    return 0;
}
