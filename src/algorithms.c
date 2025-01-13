#include "../inc/push_swap.h"

void	tiny_sort(t_stack *a)
{
	int	top = a->head->value;
	int	middle = a->head->next->value;
	int	bottom = a->head->next->next->value;

	// case: 2 1 3
	if(top > middle && middle < bottom && top < bottom)
		sa(a);
	// case: 3 2 1
	else if(top > middle && middle > bottom)
	{
		ra(a);
		sa(a);
	}
	// case: 3 1 2
	else if(top > middle && middle < bottom && top > bottom)
		ra(a);
	// case: 2 3 1
	else if(top < middle && middle > bottom && top > bottom)
	{
		rra(a);
	}
	// case: 1 3 2
	else if(top < middle && middle > bottom && top < bottom)
	{
		rra(a);
		sa(a);
	}
	
}