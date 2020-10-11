#ifndef __UNION_FIND_H_
#define __UNION_FIND_H_

// Tipo opaco para union-find
// Representa a árvore geradora mínima na execução da main

typedef struct union_find UF;

// Inicializa uma estrutura union-find
UF *UF_init(int N);

// Busca a raiz de um nó da estrutura
int UF_find(UF *graph, int node);
// Faz união entre dois nós da estrutura
void UF_union(UF *graph, int p, int q);

// Imprime raizes de todos os nós da estrutura
void UF_print(UF *graph);

// Libera a estrutura union-find e seus elementos da memória
void UF_free(UF *graph);

// Obtém o número de nós do union-find
int UF_get_N(UF *graph);
// Obtém o vetor de ids (raízes) dos nós do union-find
int *UF_get_ids(UF *graph);
// Obtém vetor de tamanhos das árvores nas quais os nós estão contidos
int *UF_get_sizes(UF *graph);

#endif
