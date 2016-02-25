/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_opts.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoureu- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 16:07:39 by dmoureu-          #+#    #+#             */
/*   Updated: 2016/02/25 23:04:18 by dmoureu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	initopts(t_opts *opts)
{
	opts->formatstart = 0;
	opts->formatend = 0;
	opts->type = 0;
	opts->flags = ft_memalloc('1');
	opts->width = 0;
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
	while (!istype(*format) && !(length && *format == '%'))
	{
		if (isflag(*format) || ft_isdigit(*format) ||
			ismod(*format) || *format == '%' || *format == '.')
		{
			length++;
			format++;
		}
		else
			break;
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

int	renderopts(t_opts *opts, va_list *pa)
{
	char	*str;
	wchar_t	*wstr;

	str = NULL;
	wstr = NULL;
	if (issigned(opts))
		str = render_opts_numeric_signed(opts, pa);
	if (isunsigned(opts))
		str = render_opts_numeric_unsigned(opts, pa);
	if (iswchar(opts))
		wstr = render_opts_wchar(opts, pa);
	else if (ischar(opts))
		str = render_opts_char(opts, pa);
	if (isptr(opts))
		str = render_opts_ptr(opts, pa);
	if (!istype(opts->type))
		str = render_opts_error(opts, pa);
	if (str)
	{
		ft_putstr(str);
		if (ft_strlen(str) == 0 && opts->type == 'c')
		{
			ft_putchar(0);
			return (1);
		}
		else if ((int)ft_strlen(str) == opts->width - 1 && opts->type == 'c')
		{
			// Cas psyche du char null qui compte pour un write...
			ft_putchar(0);
			return (ft_strlen(str) + 1);
		}
		else
			return (ft_strlen(str));
	}
	else if (wstr)
	{
		ft_putwstr(wstr);
		if (ft_wstrlen(wstr) == 0 && opts->type == 'C')
		{
			ft_putwchar(0);
			return (1);
		}
		return (ft_wstrlen(wstr));
	}
	else
	{
		if (opts->type == 0)
			return (0);
		else
		{
			ft_putstr("(null)");
			return (ft_strlen("(null)"));
		}
	}
	return (0);
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
