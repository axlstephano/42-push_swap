#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../lib/lib42.h"

typedef struct s_stack
{
    int size;
    struct s_stack *head;
}	t_stack;

typedef struct s_node
{
    int     value;
    int     index;
    struct s_node *next;
}   t_node;

#endif
