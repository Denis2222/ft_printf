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
		ft_printf("debut 𝛌 α 🦂 莨 ab %S ", L" 𝛌 α 🦂 莨 a");
//		ft_putnbr(printf("|%*s|\n", 30, "toto"));
//		printf("%120s","𝛌α🦂TOTO");
	}
	else
	{
		ft_printf(av[1], av[2], av[3]);
	}

ft_putstr("\n");

	ft_putstr(ft_strminn("𝛌α🦂TOTO", 120, 1, ' '));
	ft_putstr(ft_strmaxn("TOTO", 2));

ft_putstr("\n");

	return (0);
}
