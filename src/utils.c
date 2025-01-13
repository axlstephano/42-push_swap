#include "../inc/push_swap.h"

//**********REVISARRRRRRRRRRRR */

int	is_sorted(t_stack *stack)
{
	t_node *temp;

	temp = stack->head;
	if (!temp)
		return (0);
	while (temp->next)
	{
		if (temp->value > temp->next->value)
			return (0);
		temp = temp->next;
	}
	return (1);
}

/* void	arg_index(t_stack *stack, int len)
{
	
}


void	tinysort(t_stack *a, t_stack *b)
{
	
} */

void	sort_stacks(t_stack *a, t_stack *b, int len)
{
	if(len == 2)
		sa(a);
	else if (len == 3)
		tiny_sort(a);
/* 	else
		turk(a, b); */
		//turk algorithm
}