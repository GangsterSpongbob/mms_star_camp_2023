#include "double_link.h"

#include <stdio.h>
#include <stdlib.h>

#include "bank_acc.h"

void print_data(data *cur_data)
{
    print_account_info((bank_acc *)cur_data->value);
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
    } while (current_node != NULL);

    printf("\n");
}

double calculate_total_balance(linked_list *ll)
{
    if (ll->head == NULL || ll->tail == NULL)
    {
        return 0.0;
    }

    double total_balance = 0.0;

    node *current_node = ll->head;
    do
    {
        total_balance += get_balance((bank_acc *)current_node->cur_data->value);
        current_node = current_node->next;
    } while (current_node != NULL);

    return total_balance;
}

node *find_max_balance(linked_list *ll)
{
    if (ll->head == NULL || ll->tail == NULL)
    {
        return NULL;
    }

    double max_balance = get_balance((bank_acc *)ll->head->cur_data->value);
    node *result_node = ll->head;

    node *current_node = ll->head;

    do
    {
        double current_balance = get_balance((bank_acc *)current_node->cur_data->value);
        if (current_balance > max_balance)
        {
            max_balance = current_balance;
            result_node = current_node;
        }

        current_node = current_node->next;
    } while (current_node != NULL);

    return result_node;
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

data *create_data(void *val)
{
    data *new_data = malloc(sizeof(data));
    new_data->value = val;

    return new_data;
}

void destroy_node(node *to_destroy)
{
    free(to_destroy->cur_data);
    free(to_destroy);
}

void destroy_data(node *to_destroy)
{
    free(to_destroy->cur_data);
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

data *pop_front(linked_list *ll)
{
    if (ll->head == NULL)
    {
        perror("Cannot pop from empty linked list\n");
        exit(-1);
    }

    data *temp_data = ll->head->cur_data;

    node *second_node = ll->head->next;
    destroy_data((node *)ll->head->cur_data);
    free(ll->head);
    ll->head = second_node;

    if (ll->head == NULL)
    {
        ll->tail = NULL;
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

data *pop_back(linked_list *ll)
{
    if (ll->head == NULL)
    {
        perror("Cannot pop from empty linked list\n");
        exit(-1);
    }

    data *temp_data = ll->tail->cur_data;
    node *second_to_last_node = ll->tail->previous;
    destroy_data((node *)ll->tail->cur_data);
    free(ll->tail);
    // destroy_node(ll->tail);
    ll->tail = second_to_last_node;

    if (ll->tail == NULL)
    {
        ll->tail = NULL;
    }

    return temp_data;
}