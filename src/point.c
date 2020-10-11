#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include "../include/point.h"

struct point
{
    char *name;
    double *coordinates;
};

char *Point_get_name(Point *point)
{
    return point->name;
}

int *Point_get_coordinates(Point *point)
{
    return point->coordinates;
}

Point *Point_init(char *name, double *coordinates, int nDimensions)
{
    Point *point = malloc(sizeof(Point));

    point->name = malloc((strlen(name) + 1) * sizeof(char));
    strcpy(point->name, name);
    point->coordinates = malloc(nDimensions * sizeof(double));

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
        point_array[(int)(i / nDimensions)] = Point_init(names[(int)(i / nDimensions)], p_coordinates, nDimensions);
    }

    return point_array;
}

double calc_dist_points(Point *p1, Point *p2, int nDimensions)
{
    double sum = 0;

    for (int i = 0; i < nDimensions; i++)
    {
        sum += (p1->coordinates[i] - p2->coordinates[i]) * (p1->coordinates[i] - p2->coordinates[i]);
    }

    return sqrt(sum);
}

void print_points(Point **points, int size, int nDimensions)
{
    for (int i = 0; i < size; i++)
    {
        printf("Ponto %d\n", i);
        printf("Nome: %s\n", points[i]->name);
        for (int j = 0; j < nDimensions; j++)
        {
            printf("Coordenada %d: %f\n", j, (points[i]->coordinates)[j]);
        }
        printf("\n");
    }
}

void destroy_point(Point *p)
{
    free(p->name);
    free(p->coordinates);
    free(p);
}

void destroy_point_array(Point **points, int size)
{
    int count = 0;
    while (count < size)
    {
        destroy_point(points[count]);
        count++;
    }

    free(points);
}
