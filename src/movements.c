#include "../inc/push_swap.h"

void	swap(t_stack *stack_a, char c)
{
	t_node *temp;
	
	temp = stack_a->head; // guardamos el valor de head en temp
	stack_a->head = temp->next; // el nuevo head es el next de temp
	temp->next = stack_a->head->next;
	stack_a->head->next = temp;
}

void	push (t_stack *stack_src, t_stack *stack_dst, char c)
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


