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

/* typedef struct s_stack
{
    int size;
    t_node *head;
	t_node *tail;
}	t_node;
 */

///////////ARGS/////////////////////////

/* int	arg_len(int ac, char **av);
int	check_duplicates(int *numbers, int len);
int	*arg_to_array(int ac, char **av, int len); */

////////STACKS/////////////////////

/* void	fill_stack(t_node *stack, int number);
void	init_node(t_node *stack_a, t_node *stack_b, int len, int *numbers); */
//void	get_tail(t_node *stack);


/////////MOVEMENTS////////////////

void	swap(t_node *stack_a);
void	push (t_node *stack_src, t_node *stack_dst, char c);
void	rotate(t_node *stack);
void	reverse_rotate(t_node *stack);

///////MOVEMENTS CALL////////////

void	sa(t_node *stack);
void	sb(t_node *stack);
void	ss(t_node *stack_1, t_node *stack_2);

void	ra(t_node *stack);
void	rb(t_node *stack);
void	rr(t_node *stack_1, t_node *stack_2);

void	rra(t_node *stack);
void	rrb(t_node *stack);
void	rrr(t_node *stack_1, t_node *stack_2);

/////////UTILS//////////////////////

/* int		is_sorted(t_node *stack);
void	sort_nodes(t_node *a, t_node *b, int len);
void	tiny_sort(t_node *a); */

/////////ALGORITHMS////////////////



/////////////////////////////////////
#endif
