#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int determine_dimensions(FILE *fp)
{
    char *lineBuffer = NULL;
    size_t lineBufferSize = 0;

    if (getline(&lineBuffer, &lineBufferSize, fp) >= 0)
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
int read_input_file(FILE *fp, char **names, double *coordenates)
{
    // Inicializa variáveis para leitura de linhas
    char *lineBuffer = NULL;
    size_t lineBufferSize = 0;
    ssize_t currentLine;

    // Lê primeira linha do arquivo
    currentLine = getline(&lineBuffer, &lineBufferSize, fp);
    int nNames = 0;
    int nCoordenates = 0;
    int isName = 1;
    // Lê enquanto getline não retornar -1 para currentLine
    while (currentLine >= 0)
    {
        // Printa linha atual
        const char s[2] = ",";
        
        // A primeira entrada é uma cadeira de caracteres
        isName = 1;

        char *token;
        token = strtok(lineBuffer, s);

        // Percorre até o final da linha
        while (token != NULL)
        {
            if (isName == 1)
            {
                names[nNames] = malloc((strlen(token) + 1) * sizeof(char));
                strcpy(names[nNames], token);
                printf("%s\n", token);
                isName = 0;
                nNames++;
            }
            else
            {
                char *ptr;
                coordenates[nCoordenates] = strtod(token, &ptr);
                nCoordenates++;
            }

            // Lê próximo token da linha
            token = strtok(NULL, s);
        }
        // printf("chars=%06zd, buf size=%06zu, contents: %s", currentLine, lineBufferSize, lineBuffer);

        // Lê a próxima linha
        currentLine = getline(&lineBuffer, &lineBufferSize, fp);
    }

    for (int i = 0; i < nNames; i++)
    {
        // printf("%s\n", names[i]);
    }
    for (int i = 0; i < nCoordenates; i++)
    {
        // printf("%f\n", coordenates[i]);
    }

    // free(lineBuffer);
    lineBuffer = NULL;

    printf("\nFim da leitura.\n");

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
