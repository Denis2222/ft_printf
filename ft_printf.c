/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoureu- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/13 20:28:06 by dmoureu-          #+#    #+#             */
/*   Updated: 2016/02/13 20:47:24 by dmoureu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(char *format, ...)
{
	va_list		pa;
	t_printf	*pf;
	t_opts		*new;

	pf = newprintf(format);
	va_start(pa, format);
	while (*format != '\0')
	{
		if (*format == '%')
		{
			new = newopts(format);
			renderopts(new, &pa);
			pf->opts = addopts(&pf->opts, new);
			format += new->length;
		}
		else
			ft_putchar(*format);
		format++;
	}
	va_end(pa);

	debugprintf(pf);
	return (0);
}
