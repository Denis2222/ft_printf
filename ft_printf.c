/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoureu- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/13 20:28:06 by dmoureu-          #+#    #+#             */
/*   Updated: 2016/02/27 11:30:09 by dmoureu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	writecount(char c, int *len)
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

int		ft_printf(char *format, ...)
{
	va_list		pa;
	t_opts		*new;
	int			pos;
	int			len;

	len = 0;
	pos = 0;
	va_start(pa, format);
	while (*format)
	{
		if (*format == '%')
		{
			new = newopts(format, pos, &pa);
			len += renderopts(new, &pa);
			cleanopts(new);
			format += new->length;
			pos += new->length;
		}
		else
			writecount(*format, &len);
		incremente(&format, &pos);
	}
	va_end(pa);
	return (len);
}
