#include <stdio.h>
#include <stdlib.h>
#include "../include/linked_list.h"

// Heterogeneous linked list
struct node
{
    void *item;
    struct node *prev, *next;
};

struct linked_list
{
    Node *first, *last;
    int size;
};

void LinkedList_create(LinkedList *list)
{
    list->first = (Node *)malloc(sizeof(Node));

    list->last = list->first;
    list->first->next = NULL;

    list->size = 0;
}

Node *create_node(void *item)
{
    Node *node = malloc(sizeof(Node));

    node->item = item;
    node->next = NULL;

    return node;
}

void LinkedList_insert(LinkedList *list, void *item)
{
    // Inserindo primeiro elemento
    if (list->first == NULL)
    {
        Node *node = create_node(item);

        list->first = node;
        list->last = list->first;
    }
    else
    {
        Node *node = create_node(item);

        list->last->next = node;
        list->last = node;
    }
    list->size++;
}

void LinkedList_delete_node(LinkedList *list, Node *removedNode)
{
    // Removendo único elemento
    if (list->first == list->last)
    {
        free(list->first);
        list->first = NULL;
        list->last = NULL;
        list->size--;
        return;
    }

    if (removedNode == list->first)
    {
        list->first = removedNode->next;
    }
    if (removedNode == list->last)
    {
        list->last = list->last->prev;
    }

    removedNode->prev->next = removedNode->next;
    removedNode->next->prev = removedNode->prev;
    list->size--;

    free(removedNode);
}

void LinkedList_print(LinkedList *list)
{
    Node *current = list->first;

    printf("List size: %i.\n", list->size);

    for (int i = 0; i < list->size; i++)
    {
        printf("%d\n", current->item);
        current = current->next;
    }
}

void LinkedList_free(LinkedList *list)
{
    Node *atual = list->first;

    for (int i = 0; i < list->size; i++)
    {
        list->first = atual;
        atual = list->first->next;

        free(list->first);
    }

    list->size = 0;
    free(list);
}
