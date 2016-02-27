/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoureu- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/13 20:28:06 by dmoureu-          #+#    #+#             */
/*   Updated: 2016/02/27 08:31:10 by dmoureu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(char *format, ...)
{
	va_list		pa;
	t_printf	*pf;
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
		{
			len++;
			ft_putchar(*format);
		}
		if (*format)
		{
			format++;
			pos++;
		}
	}
	va_end(pa);
	return (len);
}
