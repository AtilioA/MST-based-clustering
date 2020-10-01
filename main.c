#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
    char *fileIn = argv[1];
    int k = atoi(argv[2]);
    char *fileOut = argv[3];

    char *line_buf = NULL;
    size_t line_buf_size = 0;
    ssize_t line_size;

    FILE *fp = fopen(fileIn, "r");

    if (!fp)
    {
        fprintf(stderr, "Falha ao abrir o arquivo '%s'.\n", fileIn);
        return EXIT_FAILURE;
    }

    printf("\n'%s' possui %i linhas.", fileIn, conta_linhas(fp));
    fclose(fp);

    return EXIT_SUCCESS;
}
