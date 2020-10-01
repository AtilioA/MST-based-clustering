// #include <stdlib.h>
#include <stdio.h>

int conta_linhas(FILE *fp)
{
    char c;
    int linhas = 0;

    if (fp == NULL)
    {
        printf("Não foi possivel abrir o arquivo.");
        return -1;
    }

    // Varre arquivo
    for (c = getc(fp); c != EOF; c = getc(fp))
    {
        if (c == '\n')
        {
            linhas++;
        }
    }

    return linhas;
}
