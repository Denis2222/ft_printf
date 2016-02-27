/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_opts_analyse.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoureu- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/22 00:12:37 by dmoureu-          #+#    #+#             */
/*   Updated: 2016/02/27 00:07:00 by dmoureu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		issigned(t_opts *opts)
{
	if (opts->type == 'd' || opts->type == 'i' || opts->type == 'D')
		return (1);
	return (0);
}

int		isunsigned(t_opts *opts)
{
	if (opts->type == 'o' || opts->type == 'O' ||
		opts->type == 'x' || opts->type == 'X' ||
		opts->type == 'u' || opts->type == 'U')
		return (1);
	return (0);
}

int		iswchar(t_opts *opts)
{
	if (opts->type == 'C' ||
		opts->type == 'S' ||
		((!ft_strcmp(opts->modify, "l")) &&
		(opts->type == 'c' || opts->type == 's')))
		return (1);
	return (0);
}

int		ischar(t_opts *opts)
{
	if (opts->type == '%' || opts->type == 'c' || opts->type == 's')
		return (1);
	return (0);
}

int		isptr(t_opts *opts)
{
	if (opts->type == 'p')
		return (1);
	return (0);
}

int		istype(char c)
{
	const char	types[14] = {"diDuUcCsSoOxXp"};

	if (ft_strchr(types, c))
		return (1);
	return (0);
}

int		isflag(char c)
{
	const char	*flags = "-+ #0";

	if (ft_strchr(flags, c))
		return (1);
	return (0);
}

int		ismod(char c)
{
	const char	*mod = "hljz";

	if (ft_strchr(mod, c))
		return (1);
	return (0);
}

int		isocta(t_opts *opts)
{
	if (opts->type == 'o' || opts->type == 'O')
		return (1);
	return (0);
}

int		ishexa(t_opts *opts)
{
	if (opts->type == 'x' || opts->type == 'X')
		return (1);
	return (0);
}

void	analysemod(t_opts *opts)
{
	const char	flags[6][4] = {"hh", "h", "ll", "l", "j", "z"};
	int			i;

	i = 0;
	(void)opts;
	while (flags[i] && i < 6 && !opts->modify)
	{
		if (ft_strstr(opts->str, flags[i]))
		{
			opts->modify = ft_strdup((char *)flags[i]);
			return ;
		}
		i++;
	}
	opts->modify = ft_strdup("");
}

void	analyseflags(t_opts *opts)
{
	char *str;

	str = opts->str;
	while (*str && (!ft_isdigit(*str) || *str == '0'))
	{
		if (isflag(*str))
		{
			if (!(opts->flags['+'] && *str == ' ') &&
				!(opts->flags['-'] && *str == '0'))
			{
				opts->flags[(int)*str] = 1;
			}
		}
		str++;
	}
}

void	delimitwidth(char *str, int *start, int *end)
{
	int	i;

	i = 0;
	*start = 0;
	*end = 0;
	while (str[i] && str[i] != '.')
	{
		if ((ft_isdigit(str[i]) || str[i] == '*') && *start == 0 && str[i] != '0')
		{
			*start = i;
			*end = i;
		}
		else if (ft_isdigit(str[i]) || str[i] == '*')
			*end = i;
		i++;
	}
}

void	analysewidth(t_opts *opts, va_list *pa)
{
	char	*str;
	int		startwidth;
	int		endwidth;
	char	*width;
	int		u;

	str = opts->str;
	delimitwidth(str, &startwidth, &endwidth);
	width = (char*)malloc(sizeof(char) * ((endwidth - startwidth + 1) + 1));
	u = 0;
	while (startwidth <= endwidth)
		width[u++] = str[startwidth++];
	width[u] = '\0';
	if (ft_strchr(width, '*'))
	{
		opts->width = va_arg(*pa, int);
	}
	else
	{
		opts->width = ft_atoi(width);
		freestr(width);
	}
}

void	analyseprecision(t_opts *opts)
{
	char	*str;
	int		nb;

	nb = 0;
	str = opts->str;
	if ((str = ft_strchr(str, '.')))
	{
		if ((nb = ft_atoi(++str)))
		{
			opts->precision = 1;
			opts->precisionn = nb;
		}
		else
			opts->precision = 1;
		if (issigned(opts) || isunsigned(opts))
			opts->flags['0'] = 0;
	}
}

void	analyseopts(t_opts *opts, va_list *pa)
{
	analyseflags(opts);
	analysewidth(opts, pa);
	analyseprecision(opts);
	analysemod(opts);
}
