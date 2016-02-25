/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoureu- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/13 20:28:06 by dmoureu-          #+#    #+#             */
/*   Updated: 2016/02/25 18:07:23 by dmoureu-         ###   ########.fr       */
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
	pf = newprintf(format);
	va_start(pa, format);
	while (*format)
	{
		//ft_putstr("@");
		if (*format == '%')
		{
			//ft_putstr("%");
			new = newopts(format, pos);
			len += renderopts(new, &pa);
			pf->opts = addopts(&pf->opts, new);
			//ft_putnbr(new->length);
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

//	debugprintf(pf);
	return (len);
}
