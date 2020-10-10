
#ifndef __DIST_H_
#define __DIST_H_

// Tipo opaco para distância entre dois pontos
#include "point.h"

typedef struct dist Dist;

Dist *create_distance_array(Point **points, int nPoints, int nDimensions);

void print_distances(Dist *distances, int nPoints);

#endif
