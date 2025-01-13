#include "../inc/push_swap.h"

//////// movements def //////////////////////

void	swap(t_stack *stack)
{
	t_node *temp;
	
	temp = stack->head; // guardamos el valor de head en temp
	stack->head = temp->next; // el nuevo head es el next de temp
	temp->next = stack->head->next;
	stack->head->next = temp;
}

void	push(t_stack *stack_src, t_stack *stack_dst, char c)
{
	t_node *temp;

	// error_handler si no existe el nodo a enviar al otro stack
	if(!stack_src || !stack_src->head)
	{
		ft_printf("src without nodes");
		return ;
	}

	temp = stack_src->head;
	stack_src->head = stack_src->head->next;
	temp->next = stack_dst->head;
	stack_dst->head = temp;
	ft_printf("p%c\n", c);
}

void	rotate(t_stack *stack)
{
	t_node	*temp;
	t_node	*temp2;

	if (!stack)
		return ;
	temp = stack->head;
	temp2= temp;
	stack->head = stack->head->next;
	while(temp2 && temp2->next)
		temp2 = temp2->next;
	temp2->next = temp;
	temp2->next->next = NULL;
}

void	reverse_rotate(t_stack *stack)
{
	t_node	*temp;
	t_node	*temp2;
	temp = stack->head;
	while(temp && temp->next)
	{
		if(!temp->next->next)
			temp2 = temp;
		temp = temp->next;
	}
	temp->next = stack->head;
	stack->head = temp;
	temp2->next = NULL;
}

////// calling movements /////////////////////

	/////// swap /////////////////////

void	sa(t_stack *stack)
{
	swap(stack);
	ft_printf("sa\n");
}

void	sb(t_stack *stack)
{
	swap(stack);
	ft_printf("sb\n");
}

void	ss(t_stack *stack_1, t_stack *stack_2)
{
	swap(stack_1);
	swap(stack_2);
	ft_printf("ss\n");
}

	/////// rotate ///////////////////

void	ra(t_stack *stack)
{
	rotate(stack);
	ft_printf("ra\n");
}

void	rb(t_stack *stack)
{
	rotate(stack);
	ft_printf("rb\n");
}

void	rr(t_stack *stack_1, t_stack *stack_2)
{
	rotate(stack_1);
	rotate(stack_2);
	ft_printf("rr\n");
}

	////// reverse rotate ///////////////

void	rra(t_stack *stack)
{
	reverse_rotate(stack);
	ft_printf("rra\n");
}

void	rrb(t_stack *stack)
{
	reverse_rotate(stack);
	ft_printf("rrb\n");
}

void	rrr(t_stack *stack_1, t_stack *stack_2)
{
	reverse_rotate(stack_1);
	reverse_rotate(stack_2);
	ft_printf("rrr\n");
}
