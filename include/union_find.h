#ifndef __UNION_FIND_H_
#define __UNION_FIND_H_

typedef struct union_find UF;

UF *UF_init(int N, int idSize);
int UF_find(UF *graph, int node);
void UF_union(UF *graph, int p, int q);
void UF_destroy(UF *graph);
int *UF_get_ids(UF *graph);
int UF_get_N(UF *graph);

#endif
