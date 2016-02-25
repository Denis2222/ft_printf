/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_opts_tools.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoureu- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 16:07:24 by dmoureu-          #+#    #+#             */
/*   Updated: 2016/02/25 20:49:20 by dmoureu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*addhexachar(char *str, int ishexa)
{
	int		length;
	char	*new;

	length = ft_strlen(str);
	if (!(length == 1 && str[0] == '0' && ishexa))
	{
		new = ft_strnew(length + 2);
		new = ft_strcat(new, "0X");
		new = ft_strcat(new, str);
	}
	else
		new = str;
	return (new);
}

char	*addoctachar(char *str)
{
	int		length;
	char	*new;

	length = ft_strlen(str);
	if (!(length == 1 && str[0] == '0'))
	{
		new = ft_strnew(length + 1);
		new = ft_strcat(new, "0");
		new = ft_strcat(new, str);
	}
	else
		new = str;
	return (new);
}

char	*applyflag(t_opts *opts, char *str)
{
	if (opts->flag == '#' && opts->type == 'x')
		return (ft_strtolower(addhexachar(str, 1)));
	if (opts->flag == '#' && opts->type == 'X')
		return (addhexachar(str, 1));
	if (opts->flag == '#' && (opts->type == 'o' || opts->type == 'O'))
		return (addoctachar(str));
	if (issigned(opts) && opts->flag == '+')
		if (str[0] != '-')
			str = straddnchar(str, 0, 1, '+');
	if (issigned(opts) && ft_isdigit(str[0]) && opts->flag == ' ')
		str = straddnchar(str, 0, 1, ' ');
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
	if (str[0] == '-' || str[0] == '+' || str[0] == ' ')
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
	if (opts->type == 'p' && opts->flag == '0')
		opts->width = opts->width - 2;
	if (opts->flag == '-')
		way = 1;
	else if (opts->flag == '0')
		c = '0';
	length = ft_strlen(str);
	if (str[0] == '\0')
		length = 1;
	if (opts->width > length)
	{
		if (issigned(opts) && opts->flag == '0')
		{
			str = straddncharsigned(str, opts->width - length, c);
		}
		else
			str = straddnchar(str, way, opts->width - length, c);
	}
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
	else if (opts->flag == '0')
		c = '0';
	length = ft_wstrlen(wstr);
	if (opts->width > length)
	{
		wstr = wstraddnchar(wstr, way, opts->width - length, c);
	}
	return (wstr);
}
