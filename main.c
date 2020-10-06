#include <stdlib.h>
#include <stdio.h>

#include "include/utils.h"
#include "include/union_find.h"

int main(int argc, char *argv[])
{
    // Teste de struct Union-Find
    UF *graph = UF_init(10);
    printf("%i %i %i\n", UF_get_ids(graph)[0], UF_get_ids(graph)[1], UF_get_ids(graph)[2]);

    printf("find 1: %i\n", UF_find(graph, 1));
    printf("find 2: %i\n", UF_find(graph, 2));
    int i = UF_find(graph, 1);
    int j = UF_find(graph, 2);
    UF_union(graph, 2, 1);
    UF_union(graph, 0, 2);
    UF_union(graph, 2, 3);
    UF_union(graph, 5, 8);

    printf("find 2: %i\n", UF_find(graph, 2));
    printf("find 1: %i\n", UF_find(graph, 1));
    printf("find 0: %i\n", UF_find(graph, 0));
    printf("find 5: %i\n", UF_find(graph, 5));
    printf("find 8: %i\n", UF_find(graph, 8));

    UF_destroy(graph);

    // Salva nome do arquivo de entrada dos argumentos
    // char *fileIn = argv[1];
    // // Salva quantidade de grupos
    // int k = atoi(argv[2]);
    // // Salva nome do arquivo de saída
    // char *fileOut = argv[3];
    // int nDimensoes;

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
    // nDimensoes = determine_dimensions(fp);
    // printf("\nDimensões: %i\n", nDimensoes);

    // /*
    // rewind(fp);
    // read_input_file(fp);
    // */

    // fclose(fp);

    return 0;
}
