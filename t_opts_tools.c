/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_opts_tools.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoureu- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 16:07:24 by dmoureu-          #+#    #+#             */
/*   Updated: 2016/02/24 23:15:47 by dmoureu-         ###   ########.fr       */
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

char	*addoctachar(char *str)
{
	int		length;
	char	*new;

	length = ft_strlen(str);
	new = ft_strnew(length + 1);
	new = ft_strcat(new, "0");
	new = ft_strcat(new, str);
	return (new);
}

char	*applyflag(t_opts *opts, char *str)
{
	if (opts->flag == '#' && opts->type == 'x')
		return (ft_strtolower(addhexachar(str)));
	if (opts->flag == '#' && opts->type == 'X')
		return (addhexachar(str));
	if (opts->flag == '#' && (opts->type == 'o' || opts->type == 'O'))
		return (addoctachar(str));
	return (str);

}

char	*applyprecision(t_opts *opts, char *str)
{
	char	*new;
	int		sign;
	int		i;

	if ((issigned(opts) || isunsigned(opts)) && opts->precisionn > 0 && opts->precision)
	{
		if (str[0] == '-' || str[0] == '+')
			sign = 1;
		else
			sign = 0;
		if (opts->precisionn > ft_strlen(str) - sign)
		{
			new = ft_strnew(opts->precisionn + sign);
			if (sign)
				new = ft_strncat(new, str, 1);
			i = sign;
			while (i < opts->precisionn - ft_strlen(str) + 2*sign)
				new[i++] = '0';
			new = ft_strcat(new, &str[sign]);
			return (new);
		}
		else
			return (str);
	}
	else if (opts->precision > 0)
	{
		new = ft_strnew(opts->precisionn);
		new = ft_strncpy(new, str, opts->precisionn);
		return (new);
	}
	else
		return (str);
}

char	*straddncharsigned(char *str, int n, char c)
{
	int		i;
	int		length;
	char	*new;
	int		sign;

	length = ft_strlen(str);
	new = ft_strnew(length + n);
	if (str[0] == '-' || str[0] == '+')
		sign = 1;
	else
		sign = 0;
	if (sign)
		new = ft_strncat(new, str, 1);
	i = sign;
	while (i < n + sign)
	{
		new[i] = c;
		i++;
	}
	new = ft_strcat(new, &str[sign]);
	return (new);
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
		if (issigned(opts) && opts->width0)
		{
			str = straddncharsigned(str, opts->width - length, c);
		}
		else
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
