#ifndef __DIST_H_
#define __DIST_H_

// Tipo opaco para distância entre dois pontos
#include "point.h"
#include "union_find.h"

typedef struct dist Dist;

// Cria vetor de distâncias a partir do vetor com todos os pontos
Dist *Dist_create_array(Point **points, int nPoints, int nDimensions);

// Imprime o vetor de distâncias
void Dist_print_array(Dist *distances, int nPoints);

// Ordena o vetor de distâncias
Dist *Dist_sort(Dist *distances, int nPoints);

// Obtém o índice do ponto P no vetor de pontos
int Dist_get_pIndex(Dist *dist);
// Obtém o índice do ponto Q no vetor de pontos
int Dist_get_qIndex(Dist *dist);
// Obtém o valor da distância entre P e Q
double Dist_get_value(Dist *dist);

// Calcula a árvore geradora mínima
UF *generate_MST_kruskal(Dist *distArray, int nPoints, char **names, int nGroups);

#endif
