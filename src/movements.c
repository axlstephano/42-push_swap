#include "../inc/push_swap.h"

//////// movements def //////////////////////

void	swap(t_stack *stack_a)
{
	t_node *temp;
	
	temp = stack_a->head; // guardamos el valor de head en temp
	stack_a->head = temp->next; // el nuevo head es el next de temp
	temp->next = stack_a->head->next;
	stack_a->head->next = temp;
}

void	push (t_stack *stack_src, t_stack *stack_dst)
{
	t_node *temp;

	// error_handler si no existe el nodo a enviar al otro stack
	if(!stack_src || !stack_src->head)
		return ;

	temp = stack_src->head;
	stack_src->head = stack_src->head->next;
	temp->next = stack_dst->head;
	stack_dst->head = temp;
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

	///////// push ///////////////////
