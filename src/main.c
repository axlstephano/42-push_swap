#include "../inc/push_swap.h"

int main (int ac, char **av)
{
	t_stack stack_a;
	t_stack stack_b;
	int len_args;

	int i = 0;

	len_args = arg_len(ac, av);
	int *matriz = arg_to_array(ac, av, len_args);
	init_stack(&stack_a, &stack_b, len_args, matriz);

	///////// TEST FUNTIONS /////////////////////

	//push(&stack_a, &stack_b, 'b'); // test para probar "pb"
	//push(&stack_b, &stack_a, 'a'); // test para probar "pa"

	////////////////////////////////////////////

	///////// TEST SHOW STACKS /////////////

		/////////// stack a /////////////////


	ft_printf("STACK A:\n");
	while (stack_a.head)
	{
		ft_printf("%d\n", stack_a.head->value);
		stack_a.head = stack_a.head->next;
	}

		/////////// stack b /////////////////

	ft_printf("STACK B:\n");
	while (stack_b.head)
	{
		ft_printf("%d\n", stack_b.head->value);
		stack_b.head = stack_b.head->next;
	}

	/////////////////////////////////

	return 0;
}
