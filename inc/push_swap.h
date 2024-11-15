#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../lib/lib42.h"


/////////////STRUCTS/////////////////////

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

///////////ARGS/////////////////////////

int	arg_len(int ac, char **av);
int	check_duplicates(int *numbers, int len);
int	*arg_to_array(int ac, char **av, int len);
void	get_tail(t_stack *stack);

////////STACKS/////////////////////

void	fill_stack(t_stack *stack, int number);
void	init_stack(t_stack *stack_a, t_stack *stack_b, int len, int *numbers);

/////////MOVEMENTS////////////////

void	swap(t_stack *stack_a);
void	push (t_stack *stack_src, t_stack *stack_dst, char c);
void	rotate(t_stack *stack);
void	reverse_rotate(t_stack *stack);

///////MOVEMENTS CALL////////////

void	sa(t_stack *stack);
void	sb(t_stack *stack);
void	ss(t_stack *stack_1, t_stack *stack_2);

/////////ALGORITHMS////////////////



/////////////////////////////////////
#endif
