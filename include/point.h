#ifndef __POINT_H_
#define __POINT_H_

// Tipo opaco para um point m-dimensional

typedef struct point Point;

// Inicializa um ponto m-dimensional
Point *Point_init(char *name, double *dimensions, int nDimensions);
// Inicializa um vetor de pontos m-dimensional
Point **Point_vector_init(char **names, double *coordenates, int nPoints, int nDimensions);
// Calcula distância entre dois pontos de mesma dimensão
double calc_dist_points(Point *p1, Point *p2, int nDimensions);

// Obtém o nome de um ponto (sequência de caracteres que o identifica)
char *Point_get_name(Point *point);
// Obtém coordenadas do ponto
int *Point_get_coordinates(Point *point);

void print_points(Point **points, int size, int nDimensions);

void Point_vector_free(Point **points, int size);

void Point_free(Point *p);

#endif
