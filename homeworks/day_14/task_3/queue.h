#ifndef QUEUE_H
#define QUEUE_H

#define MAX_ARR_LEN 128

#define CHAR 0
#define INT 1
#define DOUBLE 2
#define STRING 3

typedef struct Queue
{
    void *st_arr[MAX_ARR_LEN];
    unsigned int write_pos;
    unsigned int read_pos;
    unsigned int elem_count;
    char type;
} queue;

queue init_queue(char);

void push_to_queue(void *, queue *);
void *pop_from_queue(queue *);

void print_queue(queue *);

void print_char_queue(queue *);
void print_int_queue(queue *);
void print_double_queue(queue *);
void print_string_queue(queue *);

#endif // QUEUE_H