/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_opts_render.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoureu- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/17 13:50:53 by dmoureu-          #+#    #+#             */
/*   Updated: 2016/02/25 23:22:06 by dmoureu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*render_opts_numeric_unsigned(t_opts *opts, va_list *pa)
{
	uintmax_t		n;
	char			*s;

	if (!ft_strcmp(opts->modify, "l") || opts->type == 'O' || opts->type == 'U')
		n = (unsigned long)va_arg(*pa, uintmax_t);
	else if (!ft_strcmp(opts->modify, "hh"))
		n = (unsigned char)(va_arg(*pa, uintmax_t));
	else if (!ft_strcmp(opts->modify, "h"))
		n = (unsigned short)va_arg(*pa, uintmax_t);
	else if (!ft_strcmp(opts->modify, "ll"))
		n = (unsigned long long)va_arg(*pa, uintmax_t);
	else if (!ft_strcmp(opts->modify, "z"))
		n = (size_t)(va_arg(*pa, uintmax_t));
	else if (!ft_strcmp(opts->modify, "j"))
		n = (uintmax_t)(va_arg(*pa, uintmax_t));
	else
		n = (unsigned int)(va_arg(*pa, uintmax_t));

	if (opts->type == 'o')
		s = ft_uitoa_base(n, 8);
	else if (opts->type == 'O')
		s = ft_uitoa_base(n, 8);
	else if (opts->type == 'x')
		s = ft_strtolower(ft_uitoa_base(n, 16));
	else if (opts->type == 'X')
		s = ft_uitoa_base(n, 16);
	else if (opts->type == 'u')
		s = ft_uitoa_base(n, 10);
	else
		s = ft_uitoa_base(n, 10);

	s = applyprecision(opts, s);
	s = applywidth(opts, s);
	s = applyflag(opts, s);

	return (s);
}

char	*render_opts_numeric_signed(t_opts *opts, va_list *pa)
{
	intmax_t		n;
	char			*s;

	if (!ft_strcmp(opts->modify, "l") || opts->type == 'D')
		n = (long)va_arg(*pa, intmax_t);
	else if (!ft_strcmp(opts->modify, "hh"))
		n = (char)(va_arg(*pa, intmax_t));
	else if (!ft_strcmp(opts->modify, "h"))
		n = (short)va_arg(*pa, intmax_t);
	else if (!ft_strcmp(opts->modify, "ll"))
		n = (long long)va_arg(*pa, intmax_t);
	else if (!ft_strcmp(opts->modify, "z"))
		n = (size_t)(va_arg(*pa, intmax_t));
	else if (!ft_strcmp(opts->modify, "j"))
		n = (intmax_t)(va_arg(*pa, intmax_t));
	else
		n = (int)(va_arg(*pa, intmax_t));

	s = ft_itoa_base(n, 10);

	s = applyflag(opts, s);
	s = applyprecision(opts, s);
	s = applywidth(opts, s);

	return (s);
}

char	*render_opts_char(t_opts *opts, va_list *pa)
{
	char	*s;
	char	c;

	if (opts->type == '%')
		s = ft_strdup("%");
	else if (opts->type == 'c')
	{
		c = va_arg(*pa, int);
		s = ft_strdup(" ");
		s[0] = c;
		s = applyprecision(opts, s);
		s = applywidth(opts, s);
	}
	else
	{
		s = va_arg(*pa, char *);
		if (!s)
			return (ft_strdup("(null)"));
		s = applyprecision(opts, s);
		s = applywidth(opts, s);
	}
	return (s);
}

char	*render_opts_error(t_opts *opts, va_list *pa)
{
	char	*s;

	(void)pa;
	s = ft_strdup(" ");
	s[0] = opts->str[ft_strlen(opts->str) - 1];
	s = applywidth(opts, s);
	return (s);
}

wchar_t	*render_opts_wchar(t_opts *opts, va_list *pa)
{
	wchar_t	*w;

	if (opts->type == 'C' || (opts->type == 'c' && !ft_strcmp(opts->modify, "l")))
	{
		w = (wchar_t*)malloc(sizeof(wchar_t) * 2);
		w[0] = va_arg(*pa, int);
		w[1] = '\0';
	}
	else
	{
		w = va_arg(*pa, wchar_t *);
		if (!w)
			return (ft_wcsdup(L"(null)"));
	}
	w = (wchar_t*)applyprecision(opts, (char*)w);
	w = applywidthwchar(opts, w);
	return (w);
}

char	*render_opts_ptr(t_opts *opts, va_list *pa)
{
	char		*s;
	uintmax_t	ptr;

	ptr = va_arg(*pa, uintmax_t);
	s = ft_uitoa_base(ptr, 16);
	if (opts->flags['0'])
	{
		s = applywidth(opts, s);
		s = ft_strtolower(addhexachar(s, 0));
	}
	else
	{
		s = ft_strtolower(addhexachar(s, 0));
		s = applywidth(opts, s);
	}
	return (s);
}
