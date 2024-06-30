/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axcastil <axcastil@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 18:48:16 by axcastil          #+#    #+#             */
/*   Updated: 2024/06/30 17:52:46 by axcastil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"


// COUNT HOW MANY ARGUMENTS THERE ARE

int	args_len(int argc, char **argv)
{
	int	count;
	int	i;
	int	j;

	count = 0;
	i = 1;
	while(i < argc)
	{
		j = 0;
		while(argv[i][j])
		{
			if (ft_isdigit(argv[i][j]) && (argv[i][j + 1] == ' '
				|| argv[i][j + 1] == '\0'))
				count ++;
			else if (!ft_isdigit(argv[i][j]) && argv[i][j] != '-' 
				&& argv[i][j] != ' ')
			{
				ft_printf("error!!");
				exit (1);
			}
			j++;
		}
		i++;
	}
	return (count);
}

int	*check_numbers(int argc, char **argv, int count)
{
	
}

int main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		*numbers;
	int		count;

	count = args_len(argc, argv);
	numbers = check_numbers(argc, argv, count);
	printf("%d\n", count);
	
	return (0);
}