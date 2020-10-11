#ifndef __POINT_H_
#define __POINT_H_

// Tipo opaco para um point m-dimensional

typedef struct point Point;

// Inicializa um ponto m-dimensional
Point *Point_init(char *name, double *dimensions, int nDimensions);
// Inicializa um vetor de pontos m-dimensional
Point **Point_array_init(char **names, double *coordenates, int nPoints, int nDimensions);
// Calcula distância entre dois pontos de mesma dimensão
double calc_dist_points(Point *p1, Point *p2, int nDimensions);

// Obtém o nome de um ponto (sequência de caracteres que o identifica)
char *Point_get_name(Point *point);
// Obtém coordenadas do ponto
int *Point_get_coordinates(Point *point);

// Imprime vetor de pontos
void print_points(Point **points, int size, int nDimensions);

// Libera um ponto da memória
void destroy_point(Point *p);

// Libera vetor de pontos da memória
void destroy_point_array(Point **points, int size);

#endif
