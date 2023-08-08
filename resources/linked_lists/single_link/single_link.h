#ifndef SINGLE_LIST_H
#define SINGLE_LIST_H

#include <stdint.h>

#define UINT8 0
#define UINT16 1
#define UINT32 2
#define UINT64 3

#define CHAR 4
#define FLOAT 5
#define INT 6
#define DOUBLE 7
#define STRING 8

typedef struct Data
{
    void *value;
    uint8_t type;
} data;

typedef struct Node
{
    data *cur_data;
    struct Node *next;
} node;

typedef struct LinkedList
{
    node *head;
    node *tail;
} linked_list;

void print_data(data *);
void print_linked_list(linked_list *);

linked_list init_list();
void deinit_list(linked_list *);

data create_data(void *, uint8_t);

void push_front(data *, linked_list *);
data *pop_front(linked_list *);
void push_back(data *, linked_list *);
data *pop_back(linked_list *);

#endif // SINGLE_LIST_H