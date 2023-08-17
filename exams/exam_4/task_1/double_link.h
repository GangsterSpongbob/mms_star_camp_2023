#ifndef DOUBLE_LINK_H
#define DOUBLE_LINK_H

#include <stdint.h>

typedef struct Data
{
    void *value;
} data;

typedef struct Node
{
    data *cur_data;
    struct Node *next;
    struct Node *previous;
} node;

typedef struct LinkedList
{
    node *head;
    node *tail;
} linked_list;

void print_data(data *);
void print_linked_list(linked_list *);

double calculate_total_balance(linked_list *);
node *find_max_balance(linked_list *);

linked_list init_list();
void deinit_list(linked_list *);

data *create_data(void *);
void destroy_data(node *);
void destroy_node(node *);

node *create_node(void *);

void push_front(data *, linked_list *);
data *pop_front(linked_list *);
void push_back(data *, linked_list *);
data *pop_back(linked_list *);

#endif // DOUBLE_LINK_H