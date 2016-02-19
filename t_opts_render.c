/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_opts_render.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoureu- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/17 13:50:53 by dmoureu-          #+#    #+#             */
/*   Updated: 2016/02/19 16:42:59 by dmoureu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*render_opts_numeric_unsigned(t_opts *opts, va_list *pa)
{
	uintmax_t		n;
	char			*s;
	int				len;

	if (opts->type == 'u' || opts->type == 'o' || opts->type == 'x')
	{
		if (!ft_strcmp(opts->modify, "hh"))
			n = (unsigned char)(va_arg(*pa, uintmax_t));
		else if (!ft_strcmp(opts->modify, "h"))
			n = (unsigned short)va_arg(*pa, uintmax_t);
		else if (!ft_strcmp(opts->modify, "l"))
			n = (unsigned long)va_arg(*pa, uintmax_t);
		else if (!ft_strcmp(opts->modify, "ll"))
			n = (unsigned long long)va_arg(*pa, uintmax_t);
		else if (!ft_strcmp(opts->modify, "t"))
			n = (size_t)(va_arg(*pa, uintmax_t));
		else if (!ft_strcmp(opts->modify, "z"))
			n = (uintmax_t)(va_arg(*pa, uintmax_t));
		else if (!ft_strcmp(opts->modify, ""))
			n = (unsigned int)(va_arg(*pa, uintmax_t));
	}
	if (opts->type == 'o')
		s = ft_strtolower(ft_uitoa_base(n, 8));
	else if (opts->type == 'O')
		s = ft_uitoa_base(n, 8);
	else if (opts->type == 'x')
		s = ft_strtolower(ft_uitoa_base(n, 16));
	else if (opts->type == 'X')
		s = ft_uitoa_base(n, 16);
	else if (opts->type == 'u')
		s = ft_uitoa_base(n, 10);
	else if (opts->type == 'U')
		s = ft_uitoa_base(n, 10);
	s = applywidth(opts, s);
	return (s);
}

char	*render_opts_numeric_signed(t_opts *opts, va_list *pa)
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
			n = (long)va_arg(*pa, intmax_t);
		else if (!ft_strcmp(opts->modify, "ll"))
			n = (long long)va_arg(*pa, intmax_t);
		else if (!ft_strcmp(opts->modify, "t"))
			n = (size_t)(va_arg(*pa, intmax_t));
		else if (!ft_strcmp(opts->modify, "z"))
			n = (intmax_t)(va_arg(*pa, intmax_t));
		else if (!ft_strcmp(opts->modify, ""))
			n = (int)(va_arg(*pa, intmax_t));
	}
	if (opts->type == 'd' || opts->type == 'i')
		s = ft_itoa_base(n, 10);
	s = applywidth(opts, s);
	return (s);
}

char	*render_opts_char(t_opts *opts, va_list *pa)
{
	char	*s;
	wchar_t	*w;
	char	c;

	if (opts->type == '%')
	{
		s = ft_strdup("%");
	}
	else if (opts->type == 'c')
	{
		c = va_arg(*pa, int);
		s = ft_strdup(" ");
		s[0] = c;
	}
	else if (opts->type == 's')
	{
		s = va_arg(*pa, char *);
		if (!s)
			s = ft_strdup("(null)");
		s = applyprecision(opts, s);
		s = applywidth(opts, s);
	}
	return (s);
}

wchar_t	*render_opts_wchar(t_opts *opts, va_list *pa)
{
	wchar_t	*w;
	char	c;

	if (opts->type == 'C')
	{
		w = (wchar_t*)malloc(sizeof(wchar_t) * 2);
		w[0] = va_arg(*pa, int);
		w[1] = '\0';
	}
	else if (opts->type == 'S')
	{
		w = va_arg(*pa, wchar_t *);
	}
	return (w);
}

char	*render_opts_ptr(t_opts *opts, va_list *pa)
{
	char		*s;
	uintmax_t	ptr;

	ptr = va_arg(*pa, uintmax_t);
	s = ft_strtolower(addhexachar(ft_uitoa_base(ptr, 16)));
	return (s);
}
