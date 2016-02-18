/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoureu- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 14:02:08 by dmoureu-          #+#    #+#             */
/*   Updated: 2016/02/18 17:57:02 by dmoureu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	main(int ac, char **av)
{
	int	n;
	
	(void)n;
	(void)ac;
	(void)av;
	char *str;
	long	longmax;
	unsigned long	ulongmax;
	wchar_t *wstr;

	longmax = (922337203685477580 * 10);
	ulongmax = longmax * 2 + 15;
	if (ac == 2)
	{
		str = ft_strdup("%S");
		   n = ft_printf("test unicode %S",L"拯救者15-ISK i7悦动版");
		   ft_putnbr(n);
		   n =    printf("test unicode %s","拯救者15-ISK i7悦动版");
		   ft_putnbr(n);
		   if (n == -1)
				perror("");
	}
	else if(ac == 4)
	{
		ft_printf(av[1], av[2], ft_atoi(av[3]));
	}

	return (0);
}
