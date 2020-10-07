#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include "../include/dists.h"
#include "../include/point.h"

struct dist
{
    int pIndex;
    int qIndex;
    double value;
};

Dist *create_distance_array(char **names, double *pointsVectorizedMatrix, int nPoints, int nDimensions)
{
    int nDistances = nPoints * (nPoints - 1) / 2;
    Dist *distances = (Dist *)malloc(nDistances * sizeof(Dist));

    /* Inicializa pontos
    (nao sei o que fiz aqui)
    Point *pointsArray = (Point *)malloc(nPoints * sizeof(Point));
    for (int i = 0; i < nPoints; i + nDimensions)
    {
        for (int j = 0; j < nDimensions; j++)
        {
            pointsArray[i] = Point_init(names[i + j], pointsVectorizedMatrix[i + j], nDimensions)
        }
    }
    */

    // Calcula distância entre pontos
    for (int i = 0; i < nPoints; i++)
    {
        for (int j = i + 1; j < nPoints; j++)
        {
            printf("Distância entre %i e %i\n", i, j);
            // calc_dist_points(pointsArray[i], pointsArray[j]);
        }
    }

    return distances;
}
