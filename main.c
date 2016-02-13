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
		ft_printf("%#.0s    %c%d", av[1], '@', 2);
		ft_putnbr(printf("|%s|\n","tt"));
	}
	else
	{
		ft_printf(av[1], av[2], av[3]);
	}
	return (0);
}
