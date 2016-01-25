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
		ft_putnbr(ft_printf("[%-s %c %s]\n", av[1], '@', av[1]));
		printf("|%8.6d|\n",12345);
		printf("|%10.4f|\n",1.23456789);
	}
	return (0);
}
