#include <stdlib.h>
#include <stdio.h>

#include "include/utils.h"
#include "include/union_find.h"

int main(int argc, char *argv[])
{
    // Teste de struct Union-Find
    UF *graph = UF_init(10, 10);
    printf("%i %i %i", UF_get_ids(graph)[0], UF_get_ids(graph)[1], UF_get_ids(graph)[2]);
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

    // int nLinhas = conta_linhas(fp);
    // printf("\n'%s' possui %i linhas.", fileIn, nLinhas);

    // // Volta para o começo do arquivo
    // rewind(fp);
    // nDimensoes = determina_dimensoes(fp);
    // printf("\nDimensões: %i\n", nDimensoes);

    // /*
    // rewind(fp);
    // le_arquivo_entrada(fp);
    // */

    // fclose(fp);

    return 0;
}
