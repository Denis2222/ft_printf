/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoureu- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 14:02:08 by dmoureu-          #+#    #+#             */
/*   Updated: 2016/02/26 04:08:18 by dmoureu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>
#include <locale.h>


void	test(char *str, int value)
{
	int n;
	str = ft_strdup(str);

	ft_putstr("=============\nstr in:");
	ft_putendl(str);

	n = ft_printf(str, value);
	ft_putendl("");
	ft_putnbr(n);
	ft_putendl("");
	n = printf(str, value);
	ft_putendl("");
	ft_putnbr(n);
	ft_putendl("\n================");
}

int	main(int ac, char **av)
{
	(void)ac;
	(void)av;
	setlocale(LC_ALL,"en_US.UTF-8");
	setbuf(stdout, NULL);

//	test("%#8x", 42);
//	test("%#8x", 0);
	test("%#6o", 2500);
	test("%-#6o", 2500);
//	test("% 10.5d", 4242);
	test("%.d", 42);
//	test("%.0d", 43);
	return (0);
}
