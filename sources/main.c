/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axcastil <axcastil@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 18:48:16 by axcastil          #+#    #+#             */
/*   Updated: 2024/06/25 21:31:25 by axcastil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/* void	check_args(int ac, char **av, t_stack **stack)
{
	char	**matrix;
	int		i;

	if (ac < 2)
		exit (1);
	else if (ac == 2)
		matrix = ft_split(av[1], ' ');
	else
	{
		i = 0;
		matrix = malloc(sizeof(char *) * (ac - 1));
		while (i < (ac -1))
		{
			matrix[i] = av[i + 1];
			i++;
		}
	}
} */
void check_args(int ac, char **av, t_stack **stack)
{
    if (ac <= 1) {
        return;
    }

    char **modified_args = malloc((ac - 1) * sizeof(char *));
    if (modified_args == NULL) {
        return;
    }

    for (int i = 1; i < ac; i++) {
        modified_args[i - 1] = av[i] + 1;
    }

    for (int i = 0; i < ac - 1; i++) {
        printf("Argumento %d: %s\n", i+1, modified_args[i]);
    }

    free(modified_args);
}

int main(int ac, char **av)
{
	t_stack	*stack_a;
	//t_stack	*stack_b;
	
	check_args(ac, av, &stack_a);
	printf("%d\n", stack_a->index);
	return (0);
}
