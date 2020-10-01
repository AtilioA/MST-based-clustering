// #include <stdlib.h>
#include <stdio.h>

int determina_dimensoes(FILE *fp)
{
    char *lineBuffer = NULL;
    int lineBufferSize = 0;

    getline(&lineBuffer, &lineBufferSize, fp);

    int i, nDimensoes;
    for (i = 0, nDimensoes = 0; lineBuffer[i]; i++)
    {
        nDimensoes += (lineBuffer[i] == ',');
    }

    free(lineBuffer);

    return nDimensoes;
}

//STUB: Incompleta, apenas printa todas as linhas
int le_arquivo_entrada(FILE *fp)
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

int conta_linhas(FILE *fp)
{
    char c;
    int linhas = 0;

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
            linhas++;
        }
    }

    return linhas;
}
