#include "queue.h"

#include <stdio.h>
#include <stdlib.h>

queue init_queue(char type)
{
    if (type < CHAR || type > STRING)
    {
        type = CHAR;
    }

    queue new_queue = {{}, 0, 0, 0, type};

    return new_queue;
}

void push_to_queue(void *new_element, queue *cur_queue)
{
    if (cur_queue->elem_count == MAX_ARR_LEN)
    {
        printf("Cannot push any more elements to queue\n");
        return;
    }

    if (cur_queue->write_pos >= MAX_ARR_LEN)
    {
        perror("Error handling queue\n");
        exit(-1);
    }

    cur_queue->st_arr[cur_queue->write_pos++] = new_element;
    if (cur_queue->write_pos == MAX_ARR_LEN)
    {
        cur_queue->write_pos = 0;
    }
    cur_queue->elem_count++;
}

void *pop_from_queue(queue *cur_queue)
{
    if (cur_queue->elem_count == 0)
    {
        printf("Cannot pop from empty queue. Returning NULL\n");
        return NULL;
    }

    if (cur_queue->read_pos >= MAX_ARR_LEN)
    {
        perror("Error handling queue\n");
        exit(-1);
    }

    void *temp = cur_queue->st_arr[cur_queue->read_pos++];
    if (cur_queue->read_pos == MAX_ARR_LEN)
    {
        cur_queue->read_pos = 0;
    }
    cur_queue->elem_count--;

    return temp;
}

void print_char_queue(queue *cur_queue)
{
    if (cur_queue->type != CHAR)
    {
        perror("Error while printing\n");
        exit(-1);
    }

    for (size_t i = 0; i <= cur_queue->elem_count; i++)
    {
        printf("%c ", *(char *)(cur_queue->st_arr[cur_queue->read_pos + i]));
    }
    printf("\n");
}

void print_int_queue(queue *cur_queue)
{
    if (cur_queue->type != INT)
    {
        perror("Error while printing\n");
        exit(-1);
    }

    for (size_t i = 0; i <= cur_queue->elem_count; i++)
    {
        printf("%i ", *(int *)(cur_queue->st_arr[cur_queue->read_pos + i]));
    }
    printf("\n");
}

void print_double_queue(queue *cur_queue)
{
    if (cur_queue->type != DOUBLE)
    {
        perror("Error while printing\n");
        exit(-1);
    }

    for (size_t i = 0; i <= cur_queue->elem_count; i++)
    {
        printf("%.4lf ", *(double *)(cur_queue->st_arr[cur_queue->read_pos + i]));
    }
    printf("\n");
}

void print_string_queue(queue *cur_queue)
{
    if (cur_queue->type != STRING)
    {
        perror("Error while printing\n");
        exit(-1);
    }

    for (size_t i = 0; i <= cur_queue->elem_count; i++)
    {
        printf("%s ", (char *)(cur_queue->st_arr[cur_queue->read_pos + i]));
    }
    printf("\n");
}

void print_queue(queue *cur_queue)
{
    switch (cur_queue->type)
    {
    case CHAR:
        print_char_queue(cur_queue);
        break;

    case INT:
        print_int_queue(cur_queue);
        break;

    case DOUBLE:
        print_double_queue(cur_queue);
        break;

    case STRING:
        print_string_queue(cur_queue);
        break;

    default:
        break;
    }
}