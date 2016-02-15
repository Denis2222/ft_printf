/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoureu- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/13 20:28:06 by dmoureu-          #+#    #+#             */
/*   Updated: 2016/02/15 19:09:49 by dmoureu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(char *format, ...)
{
	va_list		pa;
	t_printf	*pf;
	t_opts		*new;
	int			pos;

	pos = 0;
	pf = newprintf(format);
	va_start(pa, format);
	while (*format != '\0')
	{
		if (*format == '%')
		{
			new = newopts(format, pos);
			renderopts(new, &pa);
			pf->opts = addopts(&pf->opts, new);
			format += new->length;
			pos += new->length;
		}
		else
			ft_putchar(*format);
		format++;
		pos++;
	}
	va_end(pa);

	debugprintf(pf);
	return (0);
}
