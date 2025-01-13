#include "../inc/push_swap.h"

int main (int ac, char **av)
{
	t_node *a;
	t_node *b;
	int len_args;
	int *matrix;

	////////ERROR HANDLER////////
	if(ac == 1 || (ac == 2 && !av[1][0]))
		return (1);

	len_args = arg_len(ac, av);
	matrix = arg_to_array(ac, av, len_args);

	init_stack(&a, &b, len_args, matrix);

	if (!is_sorted(&a))
		sort_stacks(&a, &b, len_args);

	///////// TEST SHOW STACKS /////////////

		/////////// stack a /////////////////


	ft_printf("STACK A:\n");
	while (a.head)
	{
		ft_printf("%d\n", a.head->value);
		a.head = a.head->next;
	}
	//ft_printf("nodo prev del último: %d\n", a.head->prev);
		/////////// stack b /////////////////

	ft_printf("STACK B:\n");
	while (b.head)
	{
		ft_printf("%d\n", b.head->value);
		b.head = b.head->next;
	}

	/////////////////////////////////
	
	
	//free_stacks(*a);
	return 0;
}
