#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#define UINT8 0
#define UINT16 1
#define UINT32 2
#define UINT64 3

#define CHAR 4
#define FLOAT 5
#define INT 6
#define DOUBLE 7

int main(void)
{
}

typedef struct Data
{
    void *value;
    uint8_t type;
} data;

typedef struct Node
{
    data *cur_data;
    struct node *next;
} node;

typedef struct LinkedList
{
    node *head;
    node *tail;
} linked_list;

linked_list init_list();
data *create_data(void *, uint8_t);
void delete_data(data *);
int push_front(data *);
data *pop_front();
int push_back(data *);
data *pop_back();

linked_list init_list()
{
    linked_list ll1;
    ll1.head = NULL;
    ll1.tail = NULL;

    return ll1;
}

data *create_data(void *val, uint8_t type)
{
    data *new_data = malloc(sizeof(data));
    new_data->value = val;
    new_data->type = type;

    return new_data;
}

void delete_data(data *to_del)
{
    free(to_del);
}

int push_front(data *new_data)
{
}
data *pop_front();
int push_back(void *, uint8_t);
data *pop_back(void *, uint8_t);