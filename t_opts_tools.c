/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_opts_tools.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoureu- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 16:07:24 by dmoureu-          #+#    #+#             */
/*   Updated: 2016/02/22 00:27:51 by dmoureu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*addhexachar(char *str)
{
	int		length;
	char	*new;
	length = ft_strlen(str);

	new = ft_strnew(length + 2);
	new = ft_strcat(new, "0X");
	new = ft_strcat(new, str);
	return (new);
}

char	*applyprecision(t_opts *opts, char *str)
{
	char	*new;
	if (opts->precision > 0)
	{
		new = ft_strnew(opts->precisionn);
		new = ft_strncpy(new, str, opts->precisionn);
		return (new);
	}
	else
		return (str);
}

char	*applywidth(t_opts *opts, char *str)
{
	int		length;
	int		way;
	char	c;

	c = ' ';
	way = 0;
	if (opts->flag == '-' || opts->type == 'p')
		way = 1;
	if (opts->width0)
		c = '0';
	length = ft_strlen(str);
	if (opts->width > length)
	{
		str = straddnchar(str, way, opts->width - length, c);
	}
	if ((opts->type == 'd' || opts->type == 'i' || opts->type == 'D') && ft_isdigit(str[0]) && opts->flag == ' ')
		str = straddnchar(str, 0, 1, ' ');
	return (str);
}

wchar_t *applywidthwchar(t_opts *opts, wchar_t *wstr)
{
	int		length;
	int		way;
	char	c;

	c = ' ';
	way = 0;
	if (opts->flag == '-')
		way = 1;
	if (opts->width0)
		c = '0';
	length = ft_wstrlen(wstr);
	if (opts->width > length)
	{
		wstr = wstraddnchar(wstr, way, opts->width - length, c);
	}
	return (wstr);
}
