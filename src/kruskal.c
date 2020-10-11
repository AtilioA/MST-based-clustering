#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "../include/union_find.h"
#include "../include/point.h"
#include "../include/dists.h"

/* Não consegui implementar aqui 🤔
UF *generate_MST_kruskal(Dist *distArray, Point **points_array, int nPoints)
{
    UF *MST = UF_init(nPoints);
    int pIndex = 0, qIndex = 0;

    int nDistances = (nPoints * (nPoints - 1)) / 2;

    for (int i = 0; i < nDistances; i++)
    {
        // pIndex = Dist_get_pIndex(*distArray[i]);
        Point *p = points_array[pIndex];

        // qIndex = Dist_get_qIndex(*distArray[i]);
        Point *q = points_array[pIndex];

        if (UF_find(MST, pIndex) != UF_find(MST, qIndex))
        {
            printf("Um salve %i\n", i);
            UF_union(MST, pIndex, qIndex);
        }
        else
        {
            printf("Um não salve %i\n", i);
        }
    }

    return MST;
}
*/
