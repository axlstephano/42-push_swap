#include "../inc/push_swap.h"

int	is_correct(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while(argv[i])
	{
		j = 0;
		while(argv[i][j])
		{
			if (ft_isalpha(argv[i][j]) )
			{
				
			}
			j++;
		}
		i++;
	}
}

void	init_stack(char **av, t_node)
{
	int	i;

	i = 1;
	while (av[i])
	{
		
	}
}

int main(int argc, char const *argv[])
{
	t_node *a;

	if (argc < 2 || (argc = 2 && argv[1][0] == '\0'))
		return (1);
	if(!is_correct(argc, argv))
		
	return (0);
}
