#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../lib/lib42.h"

typedef struct s_node
{
    int     value;
    int     index;
    struct s_node *next;
}   t_node;

typedef struct s_stack
{
    int size;
    t_node *head;
	t_node *tail;
}	t_stack;

void	get_tail(t_stack *stack);
void	push(t_stack *stack_a, t_stack *stack_b, char c);

#endif