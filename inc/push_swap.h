#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../lib/lib42.h"


/////////////STRUCTS/////////////////////

typedef struct s_node
{
    int     value;
    int     index;
    struct s_node *next;
	struct s_node *prev;
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

////////STACKS/////////////////////

void	fill_stack(t_stack *stack, int number);
void	init_stack(t_stack *stack_a, t_stack *stack_b, int len, int *numbers);
//void	get_tail(t_stack *stack);


/////////MOVEMENTS////////////////

void	swap(t_stack *stack_a);
void	push (t_stack *stack_src, t_stack *stack_dst, char c);
void	rotate(t_stack *stack);
void	reverse_rotate(t_stack *stack);

///////MOVEMENTS CALL////////////

void	sa(t_stack *stack);
void	sb(t_stack *stack);
void	ss(t_stack *stack_1, t_stack *stack_2);

void	ra(t_stack *stack);
void	rb(t_stack *stack);
void	rr(t_stack *stack_1, t_stack *stack_2);

void	rra(t_stack *stack);
void	rrb(t_stack *stack);
void	rrr(t_stack *stack_1, t_stack *stack_2);

/////////UTILS//////////////////////

int		is_sorted(t_stack *stack);
void	sort_stacks(t_stack *a, t_stack *b, int len);
void	tiny_sort(t_stack *a);

/////////ALGORITHMS////////////////



/////////////////////////////////////
#endif
