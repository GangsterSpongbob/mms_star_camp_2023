#include "double_link.h"
#include "book.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_data(node *cur_node)
{
    print_book(cur_node->cur_data);
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
        print_data(current_node);
        current_node = current_node->next;
    } while (current_node != NULL);

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

// data create_data(void *val, size_t size)
// {
//     data new_data;
//     new_data.value = malloc(size);
//     if (new_data.value == NULL)
//     {
//         perror("Error druing memory allocation\n");
//         exit(-1);
//     }

//     new_data.size = size;
//     memcpy(new_data.value, val, size);

//     return new_data;
// }

void push_front(book new_book, linked_list *ll)
{
    node *new_head = malloc(sizeof(node));
    if (new_head == NULL)
    {
        perror("Error during dynamic data allocation\n");
        exit(-1);
    }

    new_head->cur_data = new_book;

    new_head->previous = NULL;
    new_head->next = ll->head;

    if (ll->tail == NULL)
    {
        ll->tail = new_head;
    }
    else
    {
        ll->head->previous = new_head;
    }

    ll->head = new_head;
}

book pop_front(linked_list *ll)
{
    if (ll->head == NULL)
    {
        perror("Cannot pop from empty linked list\n");
        exit(-1);
    }

    book temp_book = ll->head->cur_data;

    node *second_node = ll->head->next;
    free(ll->head);
    ll->head = second_node;

    if (ll->head == NULL)
    {
        ll->tail = NULL;
    }

    return temp_book;
}

void push_back(book new_element, linked_list *ll)
{
    node *new_tail = malloc(sizeof(node));
    if (new_tail == NULL)
    {
        perror("Error during dynamic data allocation\n");
        exit(-1);
    }

    new_tail->cur_data = new_element;

    new_tail->next = NULL;
    new_tail->previous = ll->tail;

    if (ll->head == NULL)
    {
        ll->head = new_tail;
    }
    else
    {
        ll->tail->next = new_tail;
    }

    ll->tail = new_tail;
}

book pop_back(linked_list *ll)
{
    if (ll->head == NULL)
    {
        perror("Cannot pop from empty linked list\n");
        exit(-1);
    }

    book temp_book = ll->tail->cur_data;
    node *second_to_last_node = ll->tail->previous;
    free(ll->tail);
    ll->tail = second_to_last_node;

    if (ll->tail == NULL)
    {
        ll->tail = NULL;
    }

    return temp_book;
}