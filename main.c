/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoureu- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 14:02:08 by dmoureu-          #+#    #+#             */
/*   Updated: 2016/02/18 15:51:20 by dmoureu-         ###   ########.fr       */
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


	longmax = (922337203685477580 * 10);
//	printf("sizeof(char):%lu \n sizeof(short):%lu \n sizeof(int):%lu\n", sizeof(char), sizeof(short), sizeof(int));
//	printf("sizeof(long):%lu \n sizeof(long long):%lu \n sizeof(intmax_t):%lu \n", sizeof(long), sizeof(long long), sizeof(intmax_t));

	if (ac == 2)
	{
		str =     ft_strdup("Hello %lx|");
		ft_printf(str, longmax * 2 + 31);
		ft_printf("\n");
		   printf(str, longmax * 2 + 31);
	}
	else if(ac == 4)
{
		ft_printf(av[1], av[2], ft_atoi(av[3]));
	}

	return (0);
}
