#ifndef __LINKED_LIST_H_
#define __LINKED_LIST_H_

typedef struct node Node;
typedef struct linked_list LinkedList;
// Heterogeneous linked list

void create_list(LinkedList *list);
void insert_list(LinkedList *list, void *element);
void print_list(LinkedList *list);
void delete_from_list(LinkedList *list, Node *removedNode);
void destroy_list(LinkedList *list);

#endif
