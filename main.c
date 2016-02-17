/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoureu- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 14:02:08 by dmoureu-          #+#    #+#             */
/*   Updated: 2016/02/17 17:57:30 by dmoureu-         ###   ########.fr       */
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
		str =     ft_strdup("Hello %ld|");
		ft_printf(str, 915555555512222222 * 90);
		ft_printf("\n");
		   printf(str, 915555555512222222 * 90);
	}
	else if(ac == 4)
{
		ft_printf(av[1], av[2], ft_atoi(av[3]));
	}

	return (0);
}
