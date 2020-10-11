#ifndef __DIST_H_
#define __DIST_H_

// Tipo opaco para distância entre dois pontos
#include "point.h"

typedef struct dist Dist;

// Cria vetor de distâncias a partir do vetor com todos os pontos
Dist *Dist_create_array(Point **points, int nPoints, int nDimensions);

// Imprime o vetor de distâncias
void Dist_print_array(Dist *distances, int nPoints);

// Ordena o vetor de distâncias
Dist *Dist_sort(Dist *distances, int nPoints);

#endif
