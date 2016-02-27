/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_opts_render.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoureu- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/17 13:50:53 by dmoureu-          #+#    #+#             */
/*   Updated: 2016/02/27 09:11:17 by dmoureu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

uintmax_t	render_opts_numeric_unsigned_get(t_opts *opts, va_list *pa)
{
	uintmax_t		n;

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
	return (n);
}

char		*render_opts_numeric_uitoa(t_opts *opts, va_list *pa, uintmax_t n)
{
	char	*s;

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
	return (s);
}

int			ishexaoctacasdemerde(t_opts *opts)
{
	if ((ishexa(opts) && opts->flags['#'] && !opts->flags['0']) ||
			(isocta(opts) && opts->flags['#'] && !opts->flags['0']))
		return (1);
	return (0);
}

char		*render_opts_numeric_unsigned(t_opts *opts, va_list *pa)
{
	uintmax_t	n;
	char		*s;

	n = render_opts_numeric_unsigned_get(opts, pa);
	s = render_opts_numeric_uitoa(opts, pa, n);
	if (isocta(opts) && opts->precision && opts->precisionn)
	{
		s = applyflag(opts, s);
		s = applyprecision(opts, s);
		s = applywidth(opts, s);
	}
	else if (ishexaoctacasdemerde(opts))
	{
		s = applyprecision(opts, s);
		s = applyflag(opts, s);
		s = applywidth(opts, s);
	}
	else
	{
		s = applyprecision(opts, s);
		s = applywidth(opts, s);
		s = applyflag(opts, s);
	}
	return (s);
}

char		*render_opts_numeric_signed(t_opts *opts, va_list *pa)
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
	s = applyprecision(opts, s);
	s = applyflag(opts, s);
	s = applywidth(opts, s);
	return (s);
}

char		*render_opts_char(t_opts *opts, va_list *pa)
{
	char	*s;
	char	c;

	s = NULL;
	if (opts->type == '%')
		s = ft_strdup("%");
	else if (opts->type == 'c')
	{
		c = va_arg(*pa, int);
		s = ft_strdup(" ");
		s[0] = c;
		s = applyprecision(opts, s);
	}
	else
	{
		s = va_arg(*pa, char *);
		if (!s && !opts->precision)
			return (ft_strdup("(null)"));
		else if (!s)
			s = ft_strdup("");
		s = ft_strdup(s);
		s = applyprecision(opts, s);
	}
	s = applywidth(opts, s);
	return (s);
}

char		*render_opts_error(t_opts *opts, va_list *pa, char *str)
{
	char	*s;

	(void)pa;
	s = ft_strdup(" ");
	s[0] = opts->str[ft_strlen(opts->str) - 1];
	s = applywidth(opts, s);
	return (s);
}

wchar_t		*render_opts_wchar(t_opts *opts, va_list *pa)
{
	wchar_t	*w;

	if (opts->type == 'C' ||
		(opts->type == 'c' && !ft_strcmp(opts->modify, "l")))
	{
		w = (wchar_t*)malloc(sizeof(wchar_t) * 2);
		w[0] = va_arg(*pa, int);
		w[1] = '\0';
	}
	else
	{
		w = va_arg(*pa, wchar_t *);
		if (w)
			w = ft_wcsdup(w);
		if (!w)
			w = ft_wcsdup(L"(null)");
		w = applyprecisionwchar(opts, w);
	}
	w = applywidthwchar(opts, w);
	return (w);
}

char		*render_opts_ptr(t_opts *opts, va_list *pa)
{
	char		*s;
	uintmax_t	ptr;

	ptr = va_arg(*pa, uintmax_t);
	s = ft_uitoa_base(ptr, 16);
	if (opts->flags['0'])
	{
		s = applyprecision(opts, s);
		s = applywidth(opts, s);
		s = ft_strtolower(addhexachar(s, 0));
	}
	else
	{
		s = applyprecision(opts, s);
		s = ft_strtolower(addhexachar(s, 0));
		s = applywidth(opts, s);
	}
	return (s);
}
