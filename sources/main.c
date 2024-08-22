/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axcastil <axcastil@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 18:48:16 by axcastil          #+#    #+#             */
/*   Updated: 2024/08/22 16:31:14 by axcastil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// COUNT HOW MANY ARGUMENTS THERE ARE

static int	args_len(int argc, char **argv)
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
				ft_printf("Error - args len\n");
				exit(1);
			}
			j++;
		}
		i++;
	}
	return (count);
}

static int	check_duplicates(int *numbers, int size)
{
	int i;
	int j;

	i = 0;
	while (i < size)
	{
		j = i  + 1;
		while (j < size)
		{
			if (numbers[i] == numbers[j])
			{
				ft_printf("Error  check duplicates\n");
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

static int	*check_numbers(int argc, char **argv, int count)
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
		matrix = ft_split(argv[i], ' ');
		if (!matrix)
			return (NULL);
		k = 0;
		while (matrix[k])
			numbers[j++] = ft_atoi(matrix[k++]);
		free(matrix);
		i++;
	}
	if (check_duplicates(numbers, count))
		exit (1);
	return (numbers);
}

static void	fill_stack(t_stack *stack, int value)
{
	t_node	*temp;

	if (!(temp = (t_node *)malloc(sizeof(t_node))))
		return ;
	temp->value = value;
	temp->next = stack->head;
	stack->head = temp;
}

static void	init_stack(t_stack *stack_a, t_stack *stack_b, int count, int *numbers)
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
	get_tail(stack_a); // obtenemos la COLA del stack, para rotate y reverse rotate
	
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
	push(&stack_a, &stack_b, 'a');
	push(&stack_a, &stack_b, 'a');
	push(&stack_a, &stack_b, 'a');
	push(&stack_a, &stack_b, 'a'); 
	// *****************PRINT "COUNT"********************
	
	//ft_printf("count:%d\n", count);

	// ************PRINT "NUMBER" ELEMENTS************************

/* 	while (i < count)
		ft_printf("%d\n", numbers[i++]);
 */
	// *************IMPRIMIR LOS VALORES DE TODOS LOS NODOS EN STACK_ A*********
	
	printf("STACK A: \n");
	while(stack_a.head)
	{
		printf("%d\n", stack_a.head->value);
		stack_a.head = stack_a.head->next;
	}
	printf("STACK B: \n");
	while(stack_b.head)
	{
		printf("%d\n", stack_b.head->value);
		stack_b.head = stack_b.head->next;
	}	
	free(numbers);
	return (0);
}
