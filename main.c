#include "ft_printf.h"
#include <stdio.h>

int	main(int ac, char **av)
{
	int	n;
	
	(void)n;
	(void)ac;
	(void)av;
	if (ac == 2)
	{
		ft_printf("[%s %c %s %d]\n", av[1], '@', av[1], 3);
		printf("|%10s|\n","tt");
		//printf("|%10.4f|\n",1.23456789);
	}
	return (0);
}
