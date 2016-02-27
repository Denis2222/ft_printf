/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_opts_tools.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoureu- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 16:07:24 by dmoureu-          #+#    #+#             */
/*   Updated: 2016/02/26 22:23:38 by dmoureu-         ###   ########.fr       */
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
		freestr(str);
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
		freestr(str);
	}
	else
		new = str;
	return (new);
}

char	*applyflag(t_opts *opts, char *str)
{
	if (opts->flags['#'] && opts->type == 'x' && ft_strlen(str))
		return (ft_strtolower(addhexachar(str, 1)));
	if (opts->flags['#'] && opts->type == 'X' && ft_strlen(str))
		return (addhexachar(str, 1));
	if (opts->flags['#'] && (opts->type == 'o' || opts->type == 'O'))
		return (addoctachar(str));
	if (issigned(opts) && opts->flags['+'])
		if (str[0] != '-')
			str = straddnchar(str, 0, 1, '+');
	if (issigned(opts) && ft_isdigit(str[0]) && opts->flags[' '])
		str = straddnchar(str, 0, 1, ' ');
	return (str);

}

char	*applyprecision(t_opts *opts, char *str)
{
	char	*new;
	int		sign;
	int		i;

	if ((issigned(opts) || isunsigned(opts) || opts->type == 'p') &&
		opts->precisionn > 0 && opts->precision)
	{
		if (str[0] == '-' || str[0] == '+')
			sign = 1;
		else
			sign = 0;
		if (opts->precisionn > (int)ft_strlen(str) - sign)
		{
			new = ft_strnew(opts->precisionn + sign);
			if (sign)
				new = ft_strncat(new, str, 1);
			i = sign;
			while (i < opts->precisionn - (int)ft_strlen(str) + 2*sign)
				new[i++] = '0';
			new = ft_strcat(new, &str[sign]);
			freestr(str);
			return (new);
		}
		else
			return (str);
	}
	else if ((issigned(opts) || isunsigned(opts)))
	{
		if (str[0] == '0' && !str[1] && opts->precision)
			++str;
		return (str);
	}
	else if ((opts->precision > 0 && !opts->flags['#']) ||
			(opts->type != 'o' && opts->type != 'O' && opts->precision > 0 && opts->flags['#']))
	{
		new = ft_strnew(opts->precisionn);
		new = ft_strncpy(new, str, opts->precisionn);
		freestr(str);
		return (new);
	}
	else
		return (str);
}

wchar_t	*applyprecisionwchar(t_opts *opts, wchar_t *str)
{
	wchar_t *new;
	int		i;
	int		octets;

	if (opts->precision)
	{
		new = (wchar_t*)malloc(sizeof(char) * opts->precisionn + 1);
		octets = 0;
		i = 0;
		while (str[i] && octets + ft_wcharlen(str[i]) <= opts->precisionn)
		{
			new[i] = str[i];
			octets += ft_wcharlen(str[i]);
			i++;
		}
		new[i] = '\0';
		freewstr(str);
	}
	else
		new = str;
	return (new);
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
	freestr(str);
	return (new);
}

char	*applywidth(t_opts *opts, char *str)
{
	int		length;
	int		way;
	char	c;

	c = ' ';
	way = 0;
	if ((opts->type == 'p' && opts->flags['0']) ||
		(ishexa(opts) && opts->flags['#'] && opts->flags['0']))
	{
		opts->width = opts->width - 2;
	}
	if (isocta(opts) && opts->flags['#'] && opts->flags['0'])
	{
		opts->width = opts->width - 1;
	}
	if (opts->flags['-'])
		way = 1;
	else if (opts->flags['0'])
		c = '0';
	length = ft_strlen(str);
	if (str[0] == '\0' && opts->type == 'c')
		length = 1;
	if (opts->width > length)
	{
		if (issigned(opts) && opts->flags['0'] && !opts->flags['-'])
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
	if (opts->flags['-'])
		way = 1;
	else if (opts->flags['0'])
		c = '0';
	length = ft_wstrlen(wstr);
	if (opts->width > length)
	{
		wstr = wstraddnchar(wstr, way, opts->width - length, c);
	}
	return (wstr);
}
