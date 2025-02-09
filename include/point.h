#ifndef __POINT_H_
#define __POINT_H_

// Tipo opaco para um point m-dimensional

typedef struct point Point;

// Inicializa um ponto m-dimensional
Point *Point_init(char *name, double *dimensions, int nDimensions, int id);
// Inicializa um vetor de pontos m-dimensional
Point **Point_array_init(char **names, double *coordenates, int nPoints, int nDimensions);
// Calcula distância entre dois pontos de mesma dimensão
double Point_calc_dist(Point *p1, Point *p2, int nDimensions);

// Obtém o nome de um ponto (sequência de caracteres que o identifica)
char *Point_get_name(Point *point);
// Obtém coordenadas do ponto
double *Point_get_coordinates(Point *point);
// Obtém o id/índice do ponto no union-find
int Point_get_UFID(Point *p);

// Imprime vetor de pontos
void Point_print_array(Point **points, int size, int nDimensions);

// Libera um ponto da memória
void Point_free(Point *p);

// Libera vetor de pontos da memória
void Point_free_array(Point **points, int size);
// Ordena vetor de pontos por ordem alfabética das raízes e dos próprios pontos
Point **Point_sort(Point **points, int nPoints, void *graph);
// Ordena vetor de pontos por ordem alfabética
Point **Point_group_sort(Point **points, int nPoints, void *g);

#endif
