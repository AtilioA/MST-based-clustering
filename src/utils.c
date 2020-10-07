#include <stdlib.h>
#include <stdio.h>

int determine_dimensions(FILE *fp)
{
    char *lineBuffer = NULL;
    size_t lineBufferSize = 0;

    if (getline(&lineBuffer, &lineBufferSize, fp) == 1)
    {

        // Percorre a string da linha contando a ocorrência de vírgulas (neste caso indicam número de dimensões)
        int i, nDimensions;
        for (i = 0, nDimensions = 0; lineBuffer[i]; i++)
        {
            nDimensions += (lineBuffer[i] == ',');
        }

        free(lineBuffer);

        return nDimensions;
    }
    else
    {
        return -1;
    }
}

//STUB: Incompleta, apenas printa todas as linhas
int read_input_file(FILE *fp)
{
    // Inicializa variáveis para leitura de linhas
    char *lineBuffer = NULL;
    size_t lineBufferSize = 0;
    ssize_t currentLine;

    // Lê primeira linha do arquivo
    currentLine = getline(&lineBuffer, &lineBufferSize, fp);

    // Lê enquanto getline não retornar -1 para currentLine
    while (currentLine >= 0)
    {
        // Printa linha atual
        printf("chars=%06zd, buf size=%06zu, contents: %s", currentLine, lineBufferSize, lineBuffer);

        // Lê a próxima linha
        currentLine = getline(&lineBuffer, &lineBufferSize, fp);
    }

    free(lineBuffer);
    lineBuffer = NULL;

    return 0;
}

int count_lines(FILE *fp)
{
    char c;
    int lines = 0;

    if (fp == NULL)
    {
        printf("Não foi possivel abrir o arquivo.");
        return -1;
    }

    // Percorre arquivo contando \n (que finaliza uma linha)
    for (c = getc(fp); c != EOF; c = getc(fp))
    {
        if (c == '\n')
        {
            lines++;
        }
    }

    return lines;
}
