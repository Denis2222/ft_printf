/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoureu- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 14:02:08 by dmoureu-          #+#    #+#             */
/*   Updated: 2016/02/19 19:18:44 by dmoureu-         ###   ########.fr       */
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
	
		n = printf("%s", "暖");
		n = printf("%S", L"暖");
		n = printf("%ls", L"暖");
		n = ft_printf("%ls, %ls", L"暖", L"ح");
		//ft_putnbr(n);
		if (n == -1)
			perror("");


	}
	else if(ac == 4)
	{
		ft_printf(av[1], av[2], ft_atoi(av[3]));
	}

	return (0);
}
