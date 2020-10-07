#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include "../include/point.h"

struct point
{
    char *name;
    int *coordinates;
};

char *Point_get_name(Point *point)
{
    return point->name;
}

int *Point_get_coordinates(Point *point)
{
    return point->coordinates;
}

Point *Point_init(char *name, int *coordinates, int nDimensions)
{
    Point *point = NULL;

    point->name = malloc((strlen(name) + 1) * sizeof(char));
    strcpy(point->name, name);
    point->coordinates = malloc(nDimensions * sizeof(int));

    for (int i = 0; i < nDimensions; i++)
    {
        point->coordinates[i] = coordinates[i];
    }

    return point;
}

double calc_dist_points(Point *p1, Point *p2, int nDimensions)
{
    double sum = 0;

    for (int i = 0; i < nDimensions; i++)
    {
        sum += (p1->coordinates[i] - p2->coordinates[i]) ^ 2;
    }

    return sqrt(sum);
}
