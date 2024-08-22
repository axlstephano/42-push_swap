/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axcastil <axcastil@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 18:48:16 by axcastil          #+#    #+#             */
/*   Updated: 2024/08/22 16:30:56 by axcastil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/////////// INSTRUCTIONS //////////

void swap(t_stack *stack, char c)
{
	t_node	*temp;

	if (!stack->head || !stack->head->next)
		return ;
	temp = stack->head;
	stack->head = temp->next;
	temp->next = stack->head->next;
	stack->head->next = temp;
	

	write(1, "s", 1);
	write(1, &c, 1);
	write(1, "\n", 1);	
}

void	push(t_stack *stack_a, t_stack *stack_b, char c)
{
	t_node	*temp;
	
	if ((stack_b->head == NULL))
	{
		stack_b->head = stack_a->head;
		stack_a->head = stack_a->head->next;
		stack_b->head->next = NULL;
		return ;
	}
	temp = stack_b->head;
	stack_b->head = stack_a->head;
	stack_a->head = stack_a->head->next;
	stack_b->head->next = temp;
}

////////////////////////////////

void	get_tail(t_stack *stack)
{
	t_node *temp;

	temp = stack->head;
	while(temp)
	{
		if(temp->next == NULL)
			stack->tail = temp;
		temp = temp->next;
	}
}   