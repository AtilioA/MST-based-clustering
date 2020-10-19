#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include "../include/point.h"
#include "../include/union_find.h"

struct point
{
    char *name;
    double *coordinates;
    int id;
};

char *Point_get_name(Point *point)
{
    return point->name;
}

int Point_get_id(Point *p)
{
    return p->id;
}

double *Point_get_coordinates(Point *point)
{
    return point->coordinates;
}

Point *Point_init(char *name, double *coordinates, int nDimensions, int id)
{
    Point *point = malloc(sizeof(Point));

    point->name = malloc((strlen(name) + 1) * sizeof(char));
    strcpy(point->name, name);
    point->coordinates = malloc(nDimensions * sizeof(double));
    point->id = id;

    for (int i = 0; i < nDimensions; i++)
    {
        point->coordinates[i] = coordinates[i];
    }

    return point;
}

Point **Point_array_init(char **names, double *coordinates, int nPoints, int nDimensions)
{
    Point **point_array = malloc(nPoints * sizeof(Point *));

    // vetor auxiliar com coordenadas de cada ponto.
    double p_coordinates[nDimensions];

    for (int i = 0; i < nPoints * nDimensions; i = i + nDimensions)
    {
        for (int j = 0; j < nDimensions; j++)
        {
            p_coordinates[j] = coordinates[i + j];
        }
        point_array[(int)(i / nDimensions)] = Point_init(names[(int)(i / nDimensions)], p_coordinates, nDimensions, (int)(i / nDimensions));
    }

    return point_array;
}

double Point_calc_dist(Point *p1, Point *p2, int nDimensions)
{
    double sum = 0;

    for (int i = 0; i < nDimensions; i++)
    {
        sum += (p1->coordinates[i] - p2->coordinates[i]) * (p1->coordinates[i] - p2->coordinates[i]);
    }

    return sqrt(sum);
}

int Point_lexicographical_comparator(const void *a, const void *b, void *g)
{
    Point *p = *((Point **)a);
    Point *q = *((Point **)b);
    UF *graph = (UF *)g;

    char *pRootName = UF_get_name_by_id(graph, UF_find(graph, p->id));
    char *qRootName = UF_get_name_by_id(graph, UF_find(graph, q->id));

    int comparePointsSameGroup = strcmp(pRootName, qRootName);
    // printf("%s e %s: \nids: %d e %d\nresultado:%d\n\n", pRootName, qRootName, UF_find(graph, p->id), UF_find(graph, q->id), comparePointsSameGroup);
    if (comparePointsSameGroup != 0)
    {
        return comparePointsSameGroup;
    }
    else
    {
        char *pName = Point_get_name(p);
        char *qName = Point_get_name(q);
        return strcmp(pName, qName);
    }
}

Point **Point_sort(Point **points, int nPoints, void *g)
{
    UF *graph = (UF *)g;
    qsort_r(points, nPoints, sizeof(Point *), Point_lexicographical_comparator, graph);
    return points;
}

Point **Point_k_sort(Point **points, int nPoints, void *g)
{
    UF *graph = (UF *)g;
    int current_id = UF_find(g, points[0]->id);
    int new_group_id = points[0]->id;
    // Alterando o id das componentes conexas para ser o id do primeiro elemento, já que já estão organizados por ordem lexicográfica em cada grupo
    for (int i = 0; i < UF_get_N(g) - 1; i++)
    {
        // Caso seja de outro grupo
        if (UF_find(g, points[i]->id) != current_id)
        {
            current_id = UF_find(g, points[i]->id);
            new_group_id = points[i]->id;
        }
        UF_set_id(points[i]->id, new_group_id, g);
    }

    qsort_r(points, nPoints, sizeof(Point *), Point_lexicographical_comparator, graph);
    return points;
}

void Point_print_array(Point **points, int size, int nDimensions)
{
    for (int i = 0; i < size; i++)
    {
        printf("Ponto %d\n", points[i]->id);
        printf("Nome: %s\n", points[i]->name);
        for (int j = 0; j < nDimensions; j++)
        {
            printf("Coordenada %d: %f\n", j, (points[i]->coordinates)[j]);
        }
        printf("\n");
    }
}

void Point_free(Point *p)
{
    free(p->name);
    free(p->coordinates);
    free(p);
}

void Point_free_array(Point **points, int size)
{
    int count = 0;
    while (count < size)
    {
        Point_free(points[count]);
        count++;
    }

    free(points);
}
