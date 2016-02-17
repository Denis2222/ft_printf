/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_opts_render.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoureu- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/17 13:50:53 by dmoureu-          #+#    #+#             */
/*   Updated: 2016/02/17 17:57:31 by dmoureu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	renderoptsnumeric(t_opts *opts, va_list *pa)
{
	intmax_t		n;
	char			*s;
	int				len;
	
	if (opts->type == 'd' || opts->type == 'i')
	{
		if (!ft_strcmp(opts->modify, "hh"))
			n = (char)(va_arg(*pa, intmax_t));
		else if (!ft_strcmp(opts->modify, "h"))
			n = (short)va_arg(*pa, intmax_t);
		else if (!ft_strcmp(opts->modify, "l"))
		{
			n = (long)va_arg(*pa, intmax_t);
		}
		else if (!ft_strcmp(opts->modify, "ll"))
			n = (long long)va_arg(*pa, intmax_t);
		else if (!ft_strcmp(opts->modify, ""))
			n = (int)(va_arg(*pa, intmax_t));
	}
	else
	{
		n = (int)va_arg(*pa, int);
	}

	len = 0;
	if (opts->type == 'd' || opts->type == 'i')
		s = ft_itoa_base(n, 10);
	else if (opts->type == 'o')
		s = ft_strtolower(ft_itoa_base(n, 8));
	else if (opts->type == 'O')
		s = ft_itoa_base(n, 8);
	else if (opts->type == 'x')
		s = ft_strtolower(ft_itoa_base(n, 16));
	else if (opts->type == 'X')
		s = ft_itoa_base(n, 16);
	len += ft_strlen(s);
	ft_putstr(s);
	return (len);
}

int	renderoptsalpha(t_opts *opts, va_list *pa)
{
	int		len;
	char	*s;
	wchar_t	*w;
	char	c;

	len = 0;
	if (opts->type == '%')
	{
		len++;
		ft_putchar('%');
	}
	else if (opts->type == 'c')
	{
		len++;
		c = va_arg(*pa, int);
		ft_putchar(c);
	}
	else if (opts->type == 's')
	{
		s = va_arg(*pa, char *);
		ft_putstr(s);
		len += ft_strlen(s);
	}
	else if (opts->type == 'S')
	{
		w = va_arg(*pa, wchar_t *);
		len += ft_wstrlen(w);
		ft_putwstr(w);
	}
	return (len);
}

