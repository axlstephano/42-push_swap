#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../lib/lib42.h"

typedef struct s_stack
{
    int index;
    int	size;
    struct s_stack *next;
    struct s_stack *prev;
}	t_stack;

#endif
