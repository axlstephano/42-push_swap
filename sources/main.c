/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axcastil <axcastil@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 18:48:16 by axcastil          #+#    #+#             */
/*   Updated: 2024/06/25 19:20:46 by axcastil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	fill_stack(int ac, char **av, t_stack **stack)
{
	char	**values;
	int		i;

	if (ac == 1)
		exit(1);
	else if (ac == 2)
		values = ft_split(av[1], ' ');
	else
	{
		i = 1;
		while(av[i])
			values[i++] = av[i++];
	}
	while (ac--)
	{
		printf("%s/n", *values);
		values--;
	}
}

int main(int ac, char **av)
{
	t_stack *stack_a;
	t_stack	*stack_b;

	fill_stack(ac, av, &stack_a);
	return (0);
}
