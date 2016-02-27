/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoureu- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 14:02:08 by dmoureu-          #+#    #+#             */
/*   Updated: 2016/02/27 13:38:33 by dmoureu-         ###   ########.fr       */
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

void	teststr(char *str, char *value)
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

void	testwstr(char *str, wchar_t *value)
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

/*	test("%#8x", 42);
	test("%#8x", 0);
	test("%#6o", 2500);
	test("%-#6o", 2500);
	test("% 10.5d", 4242);
	test("%.d", 42);
	test("%.0d", 43);
	teststr("%#8s", "toto");
	teststr("%s", "toto");
	teststr("%10.2s", "toto");
	teststr("%-10.2s fait du velo", "toto");
	testwstr("%4.15S", L"我是一oijqiowjdoijqwoijdoijqwoijdoijqwoijdoiqwjiojdioqwjiodjioqwjoidjioqwjdoi只猫。");
	testwstr("%4.15S", L"我是一只猫。");
	testwstr("%4.S", L"我是一只猫。");
*/
//	test("%.d", 0);
//	test("%.0d", 0);

//	ft_printf("%b", 9999);
/*
	printf("%sred\n", KRED);
    printf("%sgreen\n", KGRN);
    printf("%syellow\n", KYEL);
    printf("%sblue\n", KBLU);
    printf("%smagenta\n", KMAG);
    printf("%scyan\n", KCYN);
    printf("%swhite\n", KWHT);
    printf("%snormal\n", KNRM);

ft_printf("{red}%b{eoc}baobab{green}%s{eoc}\n\n\n", 9999, "toto");
*/
int	w;

w = 10;
ft_printf("{blue}%+0*d{eoc}%0*d{red}%0*d{eoc}\n", w, 10, w, 0, w, 0);
ft_printf("{blue}%+0*d{eoc}%0*d{red}%0*d{eoc}\n", w, 9, w, 0, w, 0);

//	ft_printf("{%05.*d}", -15, 42);
//	ft_putendl("");
//	   printf("{%05.*d}", -15, 42);
//	printf("[%s]", 20, "toto");

//	ft_putstr(ft_itoa_base(INTMAX_MIN, 10));
	return (0);
}
