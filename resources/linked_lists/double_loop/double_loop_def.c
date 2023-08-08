#include "double_loop.h"

#include <stdio.h>
#include <stdlib.h>

void print_data(data *cur_data)
{
    switch (cur_data->type)
    {
    case UINT8:
        printf("%d ", *(int *)(cur_data->value));
        break;

    case UINT16:
        printf("%d ", *(int *)(cur_data->value));
        break;

    case UINT32:
        printf("%d ", *(int *)(cur_data->value));
        break;

    case UINT64:
        printf("%d ", *(unsigned int *)(cur_data->value));
        break;

    case CHAR:
        printf("%c ", *(char *)(cur_data->value));
        break;

    case FLOAT:
        printf("%f ", *(float *)(cur_data->value));
        break;

    case INT:
        printf("%d ", *(int *)(cur_data->value));
        break;

    case DOUBLE:
        printf("%lf ", *(double *)(cur_data->value));
        break;

    case STRING:
        printf("%s ", (char *)(cur_data->value));
        break;

    default:
        break;
    }
}

void print_linked_list(linked_list *ll)
{
    if (ll->head == NULL || ll->tail == NULL)
    {
        printf("Empty list\n");
        return;
    }

    node *current_node = ll->head;
    do
    {
        print_data(current_node->cur_data);
        current_node = current_node->next;
    } while (current_node != ll->head);
    // for (; current_node->next != ll->head; current_node = current_node->next)
    // {
    //     print_data(current_node->cur_data);
    // }
    printf("\n");
}

linked_list init_list()
{
    linked_list ll1;
    ll1.head = NULL;
    ll1.tail = NULL;

    return ll1;
}

void deinit_list(linked_list *ll)
{
    while (ll->head != NULL)
    {
        pop_front(ll);
    }
}

data create_data(void *val, uint8_t type)
{
    data new_data = {val, type};

    return new_data;
}

void push_front(data *new_element, linked_list *ll)
{
    node *new_head = malloc(sizeof(node));
    if (new_head == NULL)
    {
        perror("Error during dynamic data allocation\n");
        exit(-1);
    }

    new_head->cur_data = new_element;

    if (ll->head == NULL && ll->tail == NULL)
    {
        new_head->next = new_head;
        new_head->previous = new_head;
    }
    else
    {
        new_head->next = ll->head;
        new_head->previous = ll->tail;
    }

    ll->head = new_head;

    if (ll->tail == NULL)
    {
        ll->tail = new_head;
    }
}

data *pop_front(linked_list *ll)
{
    if (ll->head == NULL)
    {
        perror("Cannot pop from empty linked list\n");
        exit(-1);
    }

    data *temp_data = ll->head->cur_data;

    if (ll->head == ll->head->next)
    {
        free(ll->head);
        ll->head = NULL;
        ll->tail = NULL;
    }
    else
    {
        node *second_node = ll->head->next;
        free(ll->head);
        ll->head = second_node;
    }

    return temp_data;
}

void push_back(data *new_element, linked_list *ll)
{
    node *new_tail = malloc(sizeof(node));
    if (new_tail == NULL)
    {
        perror("Error during dynamic data allocation\n");
        exit(-1);
    }

    new_tail->cur_data = new_element;

    if (ll->head == NULL && ll->tail == NULL)
    {
        new_tail->next = new_tail;
        new_tail->previous = new_tail;
    }
    else
    {
        new_tail->next = ll->head;
        new_tail->previous = ll->tail;
    }

    ll->tail = new_tail;

    if (ll->head == NULL)
    {
        ll->head = new_tail;
    }
}

data *pop_back(linked_list *ll)
{
    if (ll->head == NULL)
    {
        perror("Cannot pop from empty linked list\n");
        exit(-1);
    }

    data *temp_data = ll->head->cur_data;

    if (ll->head->next == ll->head)
    {
        free(ll->head);
        ll->head = NULL;
        ll->tail = NULL;
    }
    else
    {
        node *second_to_last_node = ll->tail->previous;
        free(ll->tail);
        ll->tail = second_to_last_node;
    }

    return temp_data;
}