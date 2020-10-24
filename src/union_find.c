#include <stdio.h>
#include <stdlib.h>
#include "../include/union_find.h"
#include "../include/point.h"

struct union_find
{
    // Quantidade de nós
    int N;
    // Vetor de ids
    int *ids;
    // Vetor de pesos, para balancear
    int *sizes;
    // Vetor de nomes de pontos dos nós
    char **names;
};

UF *UF_init(int N, char **names)
{
    UF *graph = (UF *)malloc(sizeof(UF));
    int *ids = (int *)malloc(N * sizeof(int));
    int *sizes = (int *)malloc(N * sizeof(int));

    for (int i = 0; i < N; i++)
    {
        ids[i] = i;   // Cada objeto começa na sua própria componente
        sizes[i] = 1; // E com peso/tamanho 1.
    }

    graph->ids = ids;
    graph->sizes = sizes;
    graph->names = names;
    graph->N = N;

    return graph;
}

int UF_find(UF *graph, int node)
{
    int findRoot = node;

    while (findRoot != graph->ids[findRoot])
    {
        graph->ids[findRoot] = graph->ids[graph->ids[findRoot]];
        findRoot = graph->ids[findRoot];
    }

    return findRoot;
}

void UF_union(UF *graph, int p, int q)
{
    int i = UF_find(graph, p);
    int j = UF_find(graph, q);

    if (i != j)
    {
        if (graph->sizes[i] < graph->sizes[j])
        {
            graph->ids[i] = j;
            graph->sizes[j] += graph->sizes[i];
        }
        else
        {
            graph->ids[j] = i;
            graph->sizes[i] += graph->sizes[j];
        }
    }
}

void UF_print(UF *graph, Point **points)
{
    for (int i = 0; i < graph->N; i++)
    {
        printf("Ponto: %s Raiz: %s\n", Point_get_name(points[i]), UF_get_name_by_id(graph, UF_find(graph, Point_get_UFID(points[i]))));
    }
}

void UF_free(UF *graph)
{
    if (graph->ids != NULL)
    {
        free(graph->ids);
    }

    if (graph->sizes != NULL)
    {
        free(graph->sizes);
    }

    if (graph != NULL)
    {
        free(graph);
    }
}

int UF_get_N(UF *graph)
{
    return graph->N;
}

int *UF_get_ids(UF *graph)
{
    return graph->ids;
}

int *UF_get_sizes(UF *graph)
{
    return graph->sizes;
}
char **UF_get_names(UF *graph)
{
    return graph->names;
}
char *UF_get_name_by_id(UF *graph, int id)
{
    return graph->names[id];
}

void UF_set_id(int i, int j, UF *graph)
{
    graph->ids[i] = j;
}
void UF_set_sizes(int i, int size, UF *graph)
{
    graph->sizes[i] = size;
}
