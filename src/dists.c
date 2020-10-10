#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include "../include/dists.h"

struct dist
{
    int pIndex;
    int qIndex;
    double value;
};

Dist *create_distance_array(Point **points_vector, int nPoints, int nDimensions)
{
    int nDistances = (nPoints * (nPoints - 1)) / 2;
    Dist *distances = (Dist *)malloc(nDistances * sizeof(Dist));
    int count = 0;

    // Calcula distância entre pontos
    for (int i = 0; i < nPoints; i++)
    {
        for (int j = i + 1; j < nPoints; j++)
        {

            distances[count].value = calc_dist_points(points_vector[i], points_vector[j], nDimensions);
            distances[count].pIndex = i;
            distances[count].qIndex = j;
            count++;
        }
    }
    return distances;
}

void print_distances(Dist *distances, int nPoints)
{
    int nDistances = (nPoints * (nPoints - 1)) / 2;
    for (int i = 0; i < nDistances; i++)
    {
        printf("Distância entre %i e %i: %f\n", distances[i].pIndex, distances[i].qIndex, distances[i].value);
    }
}

int comparator(const void *a, const void *b)
{
    if (((Dist *)a)->value > ((Dist *)b)->value)
    {
        return 1;
    }
    else if (((Dist *)a)->value < ((Dist *)b)->value)
    {
        return -1;
    }
    else
    {
        return ((Dist *)a)->pIndex - ((Dist *)b)->pIndex;
    }
}

Dist *dist_sort(Dist *distances, int nPoints)
{
    int nDistances = (nPoints * (nPoints - 1)) / 2;
    qsort(distances, nDistances, sizeof(Dist), comparator);
    return distances;
}