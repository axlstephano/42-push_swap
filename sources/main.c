/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axcastil <axcastil@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 18:48:16 by axcastil          #+#    #+#             */
/*   Updated: 2024/07/18 19:14:08 by axcastil         ###   ########.fr       */
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
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			if (ft_isdigit(argv[i][j]) && (argv[i][j + 1] == ' ' || argv[i][j
					+ 1] == '\0'))
				count++;
			else if (!ft_isdigit(argv[i][j]) && argv[i][j] != '-'
				&& argv[i][j] != ' ')
			{
				ft_printf("error!!");
				exit(1);
			}
			j++;
		}
		i++;
	}
	return (count);
}

int	*check_numbers(int argc, char **argv, int count)
{
	int		*numbers;
	char	**matrix;
	int		i;
	int		j;
	int		k;

	i = 1;
	j = 0;
	numbers = (int *)ft_calloc(count, sizeof(int));
	if (!numbers)
		return (NULL);
	while (i < argc)
	{
		matrix = ft_split(argv[i], ' '); // split a argumento
		if (!matrix)
			return (NULL);
		k = 0;
		while (matrix[k])
			numbers[j++] = ft_atoi(matrix[k++]);
		free(matrix); // cambiar
		i++;
	}
	return (numbers);
}

void	fill_stack(t_stack *stack, int value)
{
	t_node	*node;

	if (!(node = (t_node *)malloc(sizeof(t_node))))
		return ;
	node->value = value;
	node->next = stack->head;
	stack->head = node;
}

void	init_stack(t_stack *stack_a, t_stack *stack_b, int count, int *numbers)
{
	t_node	*node;
	int		i;

	stack_a->head = NULL;
	stack_b->head = NULL;
	stack_a->size = 0;
	stack_b->size = 0;
	i = count - 1; // número de posiciones, desde el último al final
	while (i >= 0)
		fill_stack(stack_a, numbers[i--]); // rellenar stack
	
}

int	main(int argc, char **argv)
{
	t_stack	stack_a;
	t_stack	stack_b;
	int		*numbers;
	int		count;
	int		i;

	i = 0;
	count = args_len(argc, argv);
	numbers = check_numbers(argc, argv, count);
	init_stack(&stack_a, &stack_b, count, numbers);
	ft_printf("count:%d\n", count); // PRINT "COUNT"

	// ************PRINT "NUMBER" ELEMENTS************************

	
	//while (i < count)
	//	ft_printf("%d\n", numbers[i++]);
	

	// ******IMPRIMIR LOS VALORES DE TODOS LOS NODOS EN STACK_ A*********
	
	/* while(stack_a.head)
	{
		printf("%d\n", stack_a.head->value);
		stack_a.head = stack_a.head->next;
	} */

	free(numbers);
	return (0);
}
