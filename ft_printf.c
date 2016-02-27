/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoureu- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/13 20:28:06 by dmoureu-          #+#    #+#             */
/*   Updated: 2016/02/27 17:12:09 by dmoureu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	writechar(char c, int *len)
{
	(*len)++;
	ft_putchar(c);
}

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
}

void	evalcolor(char **format)
{
	const char	color[8][9] = {"{red}", "{green}", "{yellow}",
	"{blue}", "magenta", "{cyan}", "{eoc}"};
	int			i;

	if (**format == '{')
	{
		i = 0;
		while (i < 7)
		{
			if (!ft_strncmp(*format, color[i], ft_strlen(color[i])))
			{
				writecolor((char *)color[i]);
				*format += ft_strlen(color[i]);
			}
			i++;
		}
	}
}

void	intinit(int *len, int *pos)
{
	*len = 0;
	*pos = 0;
}

int		ft_printf(char *format, ...)
{
	va_list		pa;
	t_opts		*new;
	int			pos;
	int			len;

	intinit(&len, &pos);
	if (!format)
		return (-1);
	va_start(pa, format);
	while (*format)
	{
		evalcolor(&format);
		if (*format == '%')
		{
			new = newopts(format, &pos, &pa);
			len += renderopts(new, &pa);
			format += cleanopts(new);
		}
		else
			writechar(*format, &len);
		incremente(&format, &pos);
	}
	va_end(pa);
	return (len);
}
