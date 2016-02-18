/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_opts.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoureu- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 16:07:39 by dmoureu-          #+#    #+#             */
/*   Updated: 2016/02/18 17:13:15 by dmoureu-         ###   ########.fr       */
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

int	renderopts(t_opts *opts, va_list *pa)
{
	char	*str;
	wchar_t	*wstr;


	//ft_putstr("render");
	str = NULL;
	wstr = NULL;
	if (opts->type == 'd' || opts->type == 'i')
		str = render_opts_numeric_signed(opts, pa);

	if (opts->type == 'o' || opts->type == 'O' ||
		opts->type == 'x' || opts->type == 'X' ||
		opts->type == 'u' || opts->type == 'U')
		str = render_opts_numeric_unsigned(opts, pa);

	if (opts->type == '%' || opts->type == 'c' ||
		opts->type == 's')
		str = render_opts_char(opts, pa);

	if (opts->type == 'C' || opts->type == 'S')
		wstr = render_opts_wchar(opts, pa);
	
	if (str)
	{
		ft_putstr(str);
		return (ft_strlen(str));
	}
	else if (wstr)
	{
		ft_putwstr(wstr);
		return (ft_wstrlen(wstr));
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
