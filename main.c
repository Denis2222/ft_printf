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
		ft_printf("debut  | %s | %S | %c | %d", " char * abcd", L"wchar_t *𝛌 🦂  𐎍 ", '@', 2);
		ft_putnbr(printf("|%#x|\n",2235798));

		printf("𝛌 🦂 莨 abcd 𐎍  ");
	}
	else
	{
		ft_printf(av[1], av[2], av[3]);
	}
	return (0);
}
