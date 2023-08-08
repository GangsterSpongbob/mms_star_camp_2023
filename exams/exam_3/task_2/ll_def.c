#include "ll.h"

#include <stdio.h>
#include <stdlib.h>

void create_ll_from_stdin(void)
{
    unsigned int N;
    scanf("%d", &N);

    int nums[N];

    for (size_t i = 0; i < N; i++)
    {
        scanf("%d", nums + i);
    }

    node *first_node = malloc(sizeof(node));
    node *head = first_node;
    node *cur_node = first_node;

    first_node->data = nums[0];

    for (size_t i = 1; i < N; i++)
    {
        node *new_node = malloc(sizeof(node));
        new_node->data = nums[i];
        cur_node->next = new_node;
        cur_node = new_node;
    }
    cur_node->next = head;

    print_ll(head);

    cur_node = head;
    do
    {
        node *temp = cur_node;
        cur_node = cur_node->next;
        free(temp);
    } while (cur_node->next != head);
}

void print_ll(node *cll)
{
    node *head = cll;
    do
    {
        printf("%d ", cll->data);
        cll = cll->next;
    } while (cll->next != head);
}

node *insert_after(node *cll, int skip_count, int new_element)
{
    for (size_t i = 0; i < skip_count; i++)
    {
        cll = cll->next;
    }

    node *after_new = cll->next;

    node *new_node = malloc(sizeof(node));

    cll->next = new_node;
    new_node->next = after_new;

    return new_node;
}