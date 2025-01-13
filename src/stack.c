#include "../inc/push_swap.h"

////////////ARGS FUNTIONS//////////////////////////////////

// contar la cantidad de argumentos insertados y devolver un **int** 
int	arg_len(int ac, char **av)
{
	int	i; // iterará av desde el segundo argumento 
	int	j; // comienza en 0 para recorrer cada argumento
	int	len; // dirá cuantos números hay
	
	//ac iterará es el límite en el cual se puede iterar av

	i = 1;
	len = 0;
	if(ac < 2) // error_handler si solo hay un argumento
	{
		ft_printf("arguments are missing :c!!!\n");
		exit (1);
	}
	while (i < ac) // iteración de n veces hasta llegar a ac
	{
		j = 0; //inicia en 0 para iterar en cada argumento
		while (av[i][j]) // iteración de cada argumento de av
		{
			if (ft_isdigit(av[i][j]) && (av[i][j + 1] == ' ' || av[i][j + 1] == '\0')) // aumenta el valor de "len" siempre que el que le sigue sea un espacio o nulo
				len++;
			else if ((!ft_isdigit(av[i][j]) && (av[i][j] != '-' && ft_isdigit(av[i][j + 1])) && av[i][j] != ' ') 
				|| (ft_isdigit(av[i][j]) && (av[i][j + 1] == '-' || !ft_isdigit(av[i][j + 1])))) //asegurarme de que no exista una letra en los arg, o un signo '-' entre números
			{
				ft_printf("Error - arg_len\n");
				exit(1);
			}
			j++;
		}
		i++;
	}
	return(len);
}

// verifica que no existan números duplicados
int	check_duplicates(int *numbers, int len)
{
	int	i; //itera desde la posición 0
	int	j; // itera los elementos siguientes

	i = 0;
	while(i < len) // iteración del número actual con cada número siguiente
	{
		j = i + 1;
		while (j < len)
		{
			if(numbers[i] == numbers[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

// coge todos los números existentes en los argumentos **av** y los pone en un array de tipo **int** para luego, poder ser usados en los **stacks**
int	*arg_to_array(int ac, char **av, int len)
{
	int		*numbers;
	char	**matrix;
	int		i; // iterador a nivel de av
	int		k; // iterador a nivel de
	int		j; // iterador a nivel de numbers

	i = 1;
	j = 0;
	numbers = ft_calloc(len, sizeof(int)); // se crea memoria para el array de tipo "int" que retornaremos
	if (!numbers)
		return (NULL);
	while(i < ac) // se itera con 'i' todos los argumentos de av
	{
		matrix = ft_split(av[i], ' '); // con split sacamos todos los números de el actual argumento y se lo pasamos a "Matrix"
		if(!matrix)
			return(NULL);
		k = 0; // debemos iterar cada elemento de "Matrix", entonces comenzamos reiniciando el valor a 0 para recorrer desde el inicio
		while(matrix[k]) // iteramos la matriz de números para convertir todos a tipo int, con ayuda de ATOI
			numbers[j++] = atoi(matrix[k++]); //conversión ATOI
		free(matrix); // liberamos "Matrix" para pasar al siguiente argumento
		i++;
	}
	if (check_duplicates(numbers, len))
	{
		ft_printf("error-duplicates");
		exit (1);
	}
	return(numbers);
}

////////////STACK FUNTIONS/////////////////////////////////

// inserta los números al STACK_A para luego ser ordenados
void	fill_stack(t_stack *stack, int number)
{
	t_node *node;

	if(!(node = (t_node *)malloc(sizeof(t_node))))
		return ;
	node->value = number;
	if(stack->head == NULL)
	{
		stack->head = node;
		node->prev = NULL;
		node->next = NULL;
		stack->tail = node;
	}
	else
	{
		node->prev = NULL;
		stack->head->prev = node;
		node->next = stack->head;
		stack->head = node;
	}
	//stack->size += 1;
}

// creación de stacks (pilas) e inserción de los números que usaremos para ordenar.
void	init_stack(t_stack *stack_a, t_stack *stack_b, int len, int *numbers)
{
	t_node *temp;
	int i;

	// inicializamos los stacks con NULL
	stack_a->head = NULL;
	stack_b->head = NULL;
	stack_a->size = 0;
	stack_b->size = 0;

	i = len - 1;
	while(i >= 0)
		fill_stack(stack_a, numbers[i--]); // rellenamos el stack con los números de "Numbers"
	//arg_index(stack_a, len);
}

// obtiene la cola de la pila (stack)
/* void	get_tail(t_stack *stack)
{
	t_node *temp;

	while(temp && temp->next)
		temp = temp->next;
	stack->tail = temp;
} */
