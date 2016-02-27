/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_opts.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoureu- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 16:07:39 by dmoureu-          #+#    #+#             */
/*   Updated: 2016/02/27 08:29:15 by dmoureu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	initopts(t_opts *opts, char *startopts)
{
	opts->formatstart = 0;
	opts->formatend = 0;
	opts->type = 0;
	opts->flags = ft_memalloc('1');
	opts->width = 0;
	opts->precision = 0;
	opts->precisionn = 0;
	opts->modify = 0;
	opts->str = ft_strnew(opts->length + 1);
	opts->str = ft_strncpy(opts->str, startopts, opts->length + 1);
}

t_opts	*newopts(char *format, int pos, va_list *pa)
{
	t_opts	*opts;
	char	*startopts;

	startopts = format;
	opts = (t_opts*)malloc(sizeof(t_opts));
	opts->length = 0;
	while (!istype(*format) && !(opts->length && *format == '%'))
	{
		if (isflag(*format) || ft_isdigit(*format) ||
			ismod(*format) || *format == '%' ||
			*format == '.' || *format == '*')
		{
			opts->length++;
			format++;
		}
		else
			break ;
	}
	initopts(opts, startopts);
	opts->formatstart = pos;
	opts->formatend = pos + opts->length;
	opts->type = opts->str[opts->length];
	analyseopts(opts, pa);
	opts->next = NULL;
	return (opts);
}

void	cleanopts(t_opts *opts)
{
	free(opts->str);
	free(opts->flags);
	free(opts->modify);
	free(opts);
}

int		renderoptsstr(t_opts *opts, char *str)
{
	int	len;

	len = ft_strlen(str);
	ft_putstr(str);
	freestr(str);
	str = NULL;
	if (len == 0 && opts->type == 'c')
	{
		ft_putchar(0);
		return (1);
	}
	else if (len == opts->width - 1 && opts->type == 'c')
	{
		ft_putchar(0);
		return (len + 1);
	}
	else
		return (len);
}

int		renderoptswstr(t_opts *opts, wchar_t *wstr)
{
	int	len;

	len = ft_wstrlen(wstr);
	ft_putwstr(wstr);
	freewstr(wstr);
	if (len == 0 && opts->type == 'C')
	{
		ft_putwchar(0);
		return (1);
	}
	return (len);
}

int		renderoptsnull(t_opts *opts)
{
	if (opts->type == 0)
		return (0);
	else
	{
		ft_putstr("(null)");
		return (ft_strlen("(null)"));
	}
}

int		renderopts(t_opts *opts, va_list *pa)
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
	if (!istype(opts->type) && opts->type != '%')
		str = render_opts_error(opts, pa, str);
	if (str)
		return (renderoptsstr(opts, str));
	else if (wstr)
		return (renderoptswstr(opts, wstr));
	else
		return (renderoptsnull(opts));
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
