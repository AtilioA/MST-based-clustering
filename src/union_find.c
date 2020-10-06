#include <stdlib.h>
#include "../include/union_find.h"

struct union_find
{
    int *id;
    int N;
};

UF *UF_init(int N, int idSize)
{
    UF *graph = (UF *)malloc(sizeof(UF));

    int *id = (int *)malloc(idSize * sizeof(int));

    for (int i = 0; i < N; i++)
    {
        id[i] = i; // Cada objeto comeca na sua propria componente.
    }              // N acessos ao array.

    graph->id = id;
    graph->N = N;

    return graph;
}

int UF_find(UF *graph, int node)
{
    int findRoot = node;
    while (findRoot != graph->id[findRoot])
    {
        findRoot = graph->id[findRoot]; // Buscar o pai ate a raiz.
    }

    return findRoot; // Profundidade de i acessos.
}

void UF_union(UF *graph, int p, int q)
{
    int i = UF_find(graph, p); // Modifique raiz de p para a raiz de q.
    int j = UF_find(graph, q); // Profundidade de p+q acessos.
    graph->id[i] = j;
}

void UF_destroy(UF *graph)
{
    free(graph->id);
    free(graph);
}

int *UF_get_ids(UF *graph)
{
    return graph->id;
}

int UF_get_N(UF *graph)
{
    return graph->N;
}
