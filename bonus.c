/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoureu- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/29 18:39:28 by dmoureu-          #+#    #+#             */
/*   Updated: 2016/02/29 18:56:36 by dmoureu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	incremente(char **format, int *pos)
{
	if (**format)
	{
		(*format)++;
		(*pos)++;
	}
}

void	writecolor(char *str)
{
	if (!ft_strcmp("{red}", str))
		ft_putstr(KRED);
	else if (!ft_strcmp("{green}", str))
		ft_putstr(KGRN);
	else if (!ft_strcmp("{yellow}", str))
		ft_putstr(KYEL);
	else if (!ft_strcmp("{blue}", str))
		ft_putstr(KBLU);
	else if (!ft_strcmp("{magenta}", str))
		ft_putstr(KMAG);
	else if (!ft_strcmp("{cyan}", str))
		ft_putstr(KCYN);
	else if (!ft_strcmp("{eoc}", str))
		ft_putstr(KNRM);
	else if (!ft_strcmp("{bold}", str))
		ft_putstr(KBOL);
}

void	evalcolor(char **format, va_list *pa, int len)
{
	const char	color[10][9] = {"{red}", "{green}", "{yellow}",
	"{blue}", "magenta", "{cyan}", "{eoc}", "{bold}"};
	int			i;
	int *e;

	if (**format == '{')
	{
		i = 0;
		while (i < 8)
		{
			if (!ft_strncmp(*format, color[i], ft_strlen(color[i])))
			{
				writecolor((char *)color[i]);
				*format += ft_strlen(color[i]);
			}
			i++;
		}
	}
	else if (ft_strncmp(*format, "%n", 2) == 0)
	{
		e = va_arg(*pa, int*);
		*e = len;
		*format += 2;
	}
}

