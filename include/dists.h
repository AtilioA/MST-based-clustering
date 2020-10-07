
#ifndef __DIST_H_
#define __DIST_H_

// Tipo opaco para distância entre dois pontos

typedef struct dist Dist;

Dist *create_distance_array(char **names, double *pointsVectorizedMatrix, int nPoints, int nDimensions);

#endif
