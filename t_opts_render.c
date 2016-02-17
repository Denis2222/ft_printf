/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_opts_render.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoureu- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/17 13:50:53 by dmoureu-          #+#    #+#             */
/*   Updated: 2016/02/17 14:38:19 by dmoureu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	renderoptsnumeric(t_opts *opts, va_list *pa)
{
	long long int	n;
	char	*s;
	int		len;

	if (ft_strcmp(opts->modify, "hh") && (opts->type == 'd' || opts->type == 'i'))
	{
		n = (va_arg(*pa, int));
		n = n % 256;
		ft_putstr("n:");
		ft_putnbr(n);
		ft_putstr("**");
	}
	else if (ft_strcmp(opts->modify, "h") && (opts->type == 'd' || opts->type == 'i'))
		n = (short)va_arg(*pa, int);
	else if (ft_strcmp(opts->modify, "l") && (opts->type == 'd' || opts->type == 'i'))
		n = (long int)va_arg(*pa, long int);
	else if (ft_strcmp(opts->modify, "ll") && (opts->type == 'd' || opts->type == 'i'))
		n = (long long int)va_arg(*pa, long long int);
	else
		n = (long long int)va_arg(*pa, long long int);

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
		s = (char *)va_arg(*pa, char *);
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

