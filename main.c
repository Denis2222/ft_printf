/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoureu- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 14:02:08 by dmoureu-          #+#    #+#             */
/*   Updated: 2016/02/16 15:57:29 by dmoureu-         ###   ########.fr       */
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
	if (ac == 2)
	{
		str =     ft_strdup("Hello %O|");
		ft_putnbr(ft_printf(str, 255));
		ft_putnbr(   printf(str, 255));
//		printf("%ld",2110111111111111111);
	}
	else
	{
		ft_printf(av[1], av[2], av[3]);
	}

	return (0);
}
