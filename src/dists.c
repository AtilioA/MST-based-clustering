#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include "../include/dists.h"
#include "../include/union_find.h"

struct dist
{
    int pIndex;
    int qIndex;
    double value;
};

Dist *Dist_create_array(Point **points_array, int nPoints, int nDimensions)
{
    int nDistances = (nPoints * (nPoints - 1)) / 2;
    Dist *distances = (Dist *)malloc(nDistances * sizeof(Dist));
    int count = 0;

    // Calcula distância entre pontos
    for (int i = 0; i < nPoints; i++)
    {
        for (int j = i + 1; j < nPoints; j++)
        {
            distances[count].value = Point_calc_dist(points_array[i], points_array[j], nDimensions);
            distances[count].pIndex = i;
            distances[count].qIndex = j;
            count++;
        }
    }
    return distances;
}

void Dist_print_array(Dist *distances, int nPoints)
{
    int nDistances = (nPoints * (nPoints - 1)) / 2;
    for (int i = 0; i < nDistances; i++)
    {
        printf("Distância entre %i e %i: %f\n", distances[i].pIndex, distances[i].qIndex, distances[i].value);
    }
}

// Comparador entre duas distâncias
int comparator(const void *d1, const void *d2)
{
    if (((Dist *)d1)->value > ((Dist *)d2)->value)
    {
        return 1;
    }
    else if (((Dist *)d1)->value < ((Dist *)d2)->value)
    {
        return -1;
    }
    else
    {
        return ((Dist *)d1)->pIndex - ((Dist *)d2)->pIndex;
    }
}

Dist *Dist_sort(Dist *distances, int nPoints)
{
    int nDistances = (nPoints * (nPoints - 1)) / 2;

    qsort(distances, nDistances, sizeof(Dist), comparator);

    return distances;
}

UF *generate_MST_kruskal(Dist *distArray, Point **points_array, int nPoints)
{
    UF *MST = UF_init(nPoints);
    int pIndex = 0, qIndex = 0;

    int nDistances = (nPoints * (nPoints - 1)) / 2;

    for (int i = 0; i < nDistances; i++)
    {
        pIndex = distArray[i].pIndex;
        Point *p = points_array[pIndex];

        qIndex = distArray[i].qIndex;
        Point *q = points_array[pIndex];

        if (UF_find(MST, pIndex) != UF_find(MST, qIndex))
        {
            // printf("Iteração nº%i:\tfind %i != %i\tDist: %lf\n", i, qIndex, pIndex, distArray[i].value);
            UF_union(MST, pIndex, qIndex);
        }
        else
        {
            // printf("Iteração nº%i:\tfind %i == %i\tDist: %lf\n", i, qIndex, pIndex, distArray[i].value);
        }
    }

    return MST;
}

int Dist_get_pIndex(Dist *dist)
{
    return dist->pIndex;
}

int Dist_get_qIndex(Dist *dist)
{
    return dist->qIndex;
}

double Dist_get_value(Dist *dist)
{
    return dist->value;
}
