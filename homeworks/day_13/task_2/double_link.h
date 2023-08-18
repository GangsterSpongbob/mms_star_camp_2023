#ifndef DOUBLE_LINK_H
#define DOUBLE_LINK_H

#include <stdint.h>
#include <stddef.h>

#include "book.h"

typedef struct Node
{
    book cur_data;
    struct Node *next;
    struct Node *previous;
} node;

typedef struct LinkedList
{
    node *head;
    node *tail;
} linked_list;

void print_data(node *);
void print_linked_list(linked_list *);

linked_list init_list();
void deinit_list(linked_list *);

void push_front(book, linked_list *);
book pop_front(linked_list *);
void push_back(book, linked_list *);
book pop_back(linked_list *);

#endif // DOUBLE_LINK_H