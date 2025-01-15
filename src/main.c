#include "../inc/push_swap.h"

void	argument_handler(int argc, char const *argv[])
{
	if (argc == 2)
		argv = ft_split (argv[1], ' ');
	
}

int main(int argc, char const *argv[])
{

	// error handling
	if (argc < 2 || (argc = 2 && argv[1][0] == '\0')) //<-- if no arguments
		return (1);

	argument_handler(argc, argv);
	return (0);
}
