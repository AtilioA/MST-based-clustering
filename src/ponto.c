#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include "Ponto.h"

struct ponto
{
    char *name;
    int *dimensions;
};

Ponto *Ponto_init(char *name, int *dimensions)
{
    Ponto *p;
    int M = sizeof(dimensions) / sizeof(dimensions[0]);
    p->name = malloc((strlen(name) + 1) * sizeof(char));
    strcpy(p->name, name);
    p->dimensions = malloc(M * sizeof(int));
    for (size_t i = 0; i < M; i++)
    {
        p->dimensions[i] = dimensions[i];
    }
    return p;
}

double calc_dist(Ponto *p1, Ponto *p2)
{
    int M = sizeof(p1->dimensions) / sizeof(p1->dimensions[0]);
    double sum = 0;
    for (size_t i = 0; i < M; i++)
    {
        sum += (p1->dimensions[i] - p2->dimensions[i]) ^ 2;
    }
    return sqrt(sum);
}