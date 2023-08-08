#ifndef LL_H
#define LL_H

typedef struct Node
{
    int data;
    struct Node *next;
} node;

void create_ll_from_stdin();
void print_ll(node *);
node *insert_after(node *, int, int);

#endif // LL_H