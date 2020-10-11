#include <stdlib.h>
#include "../include/union_find.h"

struct union_find
{
    int N;
    int *ids;
    int *sizes;
};

UF *UF_init(int N)
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
