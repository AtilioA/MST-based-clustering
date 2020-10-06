#ifndef __LINKED_LIST_H_
#define __LINKED_LIST_H_

// Tipo opaco para lista encadeada heterogênea

typedef struct node Node;
typedef struct linked_list LinkedList;

// Cria uma lista vazia
void create_list(LinkedList *list);

// Insere um elemento numa lista existente
void insert_list(LinkedList *list, void *element);
// Imprime os conteúdos de uma lista
void print_list(LinkedList *list);
// Deleta um elemento de uma lista
void delete_from_list(LinkedList *list, Node *removedNode);

// Libera uma lista e seus elementos da memória
void destroy_list(LinkedList *list);

#endif
