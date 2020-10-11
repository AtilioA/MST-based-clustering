#ifndef __LINKED_LIST_H_
#define __LINKED_LIST_H_

// Tipo opaco para lista encadeada heterogênea

typedef struct node Node;
typedef struct linked_list LinkedList;

// Cria uma lista vazia
void LinkedList_create(LinkedList *list);

// Insere um elemento numa lista existente
void LinkedList_insert(LinkedList *list, void *element);
// Imprime os conteúdos de uma lista
void LinkedList_print(LinkedList *list);
// Deleta um elemento de uma lista
void LinkedList_delete_node(LinkedList *list, Node *removedNode);

// Libera uma lista e seus elementos da memória
void LinkedList_free(LinkedList *list);

#endif
