/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoureu- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 14:02:08 by dmoureu-          #+#    #+#             */
/*   Updated: 2016/02/21 18:10:49 by dmoureu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>

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
	char	*mstr;
	char	*str2;

	longmax = (922337203685477580 * 10);
	ulongmax = longmax * 2 + 15;
	if (ac == 2)
	{
		mstr = 0;
	
		ft_printf("ft_printf:\n");
		n = ft_printf("{%10R}");
		ft_putnbr(n);
		ft_putendl("\n--------\nprintf:");
		n =    printf("{%10R}", 2);
		printf("%d", n);
		//if (n == -1)
		//	perror("");
	}
	else if(ac == 4)
	{
		ft_printf(av[1], av[2], ft_atoi(av[3]));
	}

	return (0);
}
