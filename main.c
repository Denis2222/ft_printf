/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoureu- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 14:02:08 by dmoureu-          #+#    #+#             */
/*   Updated: 2016/02/25 23:23:21 by dmoureu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>
#include <locale.h>

int	main(int ac, char **av)
{
	int		n;
	char	*str;
	(void)ac;
	(void)av;
	setlocale(LC_ALL,"en_US.UTF-8");
	setbuf(stdout, NULL);
	str = ft_strdup("%4.15S");

	ft_putstr("str in:");
	ft_putendl(str);
	
	n = ft_printf(str, L"我是一只猫。");
	ft_putendl("");
	ft_putnbr(n);
	ft_putendl("");
	n = printf(str, L"我是一只猫。");
	ft_putendl("");
	ft_putnbr(n);
	return (0);
}
