/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_opts.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoureu- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 16:07:39 by dmoureu-          #+#    #+#             */
/*   Updated: 2016/02/16 16:18:19 by dmoureu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	initopts(t_opts *opts)
{
	opts->formatstart = 0;
	opts->formatend = 0;
	opts->type = 0;
	opts->flag = 0;
	opts->width = 0;
	opts->width0 = 0;
	opts->precision = 0;
	opts->precisionn = 0;
	opts->modify = 0;
}

t_opts	*newopts(char *format, int pos)
{
	t_opts	*opts;
	int		length;
	char	*startopts;

	startopts = format;
	opts = (t_opts*)malloc(sizeof(t_opts));
	length = 0;
	while (!istype(*format))
	{
		length++;
		format++;
	}
	opts->str = ft_strnew(length + 1);
	opts->str = ft_strncpy(opts->str, startopts, length + 1);
	initopts(opts);
	opts->formatstart = pos;
	opts->formatend = pos + length;
	opts->type = opts->str[length];
	opts->length = length;
	analyseopts(opts);
	opts->next = NULL;
	return (opts);
}

int	renderoptsnumeric(t_opts *opts, va_list *pa)
{
	int		n;
	char	*s;
	int		len;

	len = 0;
	if (opts->type == 'd' || opts->type == 'i')
	{
		n = va_arg(*pa, int);
		s = ft_itoa_base(n, 10);
		len += ft_strlen(s);
		ft_putstr(s);
	}
	else if (opts->type == 'o')
	{
		n = va_arg(*pa, long long int);
		s = ft_strtolower(ft_itoa_base(n, 8));
		len += ft_strlen(s);
		ft_putstr(s);
	}
	else if (opts->type == 'O')
	{
		n = va_arg(*pa, long long int);
		s = ft_itoa_base(n, 8);
		len += ft_strlen(s);
		ft_putstr(s);
	}
	else if (opts->type == 'x')
	{
		n = va_arg(*pa, long long int);
		s = ft_strtolower(ft_itoa_base(n, 16));
		len += ft_strlen(s);
		ft_putstr(s);
	}
	else if (opts->type == 'X')
	{
		n = va_arg(*pa, long long int);
		s = ft_itoa_base(n, 16);
		len += ft_strlen(s);
		ft_putstr(s);
	}
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

int	renderopts(t_opts *opts, va_list *pa)
{
	int		len;

	len = 0;
	len += renderoptsnumeric(opts, pa);
	len += renderoptsalpha(opts, pa);
	return (len);
}

t_opts	*addopts(t_opts **lst, t_opts *new)
{
	t_opts	*beginlst;
	t_opts	*current;

	beginlst = *lst;
	current = beginlst;
	if (!*lst)
		beginlst = new;
	else
	{
		while (current->next)
			current = current->next;
		current->next = new;
	}
	return (beginlst);
}
