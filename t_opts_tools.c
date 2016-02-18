/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_opts_tools.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoureu- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 16:07:24 by dmoureu-          #+#    #+#             */
/*   Updated: 2016/02/18 16:04:29 by dmoureu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int istype(char c)
{
	char	*types = "diDuUcCsSoOxXp";
	if (ft_strchr(types, c))
		return (1);
	return (0);
}

int	isflag(char c)
{
	char	*flags = "-+ #";
	if (ft_strchr(flags, c))
			return (1);
	return (0);
}

void	analysemod(t_opts *opts)
{
	char	flags[6][4] = {"hh", "h", "ll", "l", "j", "z"};
	int		i;

	i = 0;
	(void)opts;
	while (flags[i] && i < 6 && !opts->modify)
	{
		if (ft_strstr(opts->str, flags[i]))
		{
			opts->modify = ft_strdup(flags[i]);
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
	while (!isflag(*str) && *str)
		str++;
	if (isflag(*str))
		opts->flag = *str;
}

void	analysewidth(t_opts *opts)
{
	char	*str;
	int		startwidth;
	int		endwidth;
	int		i;
	char	*width;
	int		u;

	str = opts->str;
	i = 0;
	startwidth = 0;
	endwidth = 0;
	while (str[i] && str[i] != '.')
	{
		if (ft_isdigit(str[i]) && startwidth == 0)
		{
			startwidth = i;
			endwidth = i;
		}
		else if(ft_isdigit(str[i]))
			endwidth = i;
		i++;
	}

	width = (char*)malloc(sizeof(char) * ((endwidth - startwidth + 1) + 1));
	i = startwidth;
	u = 0;
	while(i <= endwidth)
	{
		width[u] = str[i];
		u++;
		i++;
	}
	width[u] = '\0';
	if (width[0] == '0')
		opts->width0 = 1;
	opts->width = ft_atoi(width);
	free(width);
//	ft_putstr("fin analyse opts");
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
	}
}

void	analyseopts(t_opts *opts)
{
	analyseflags(opts);
	analysewidth(opts);
	analyseprecision(opts);
	analysemod(opts);
}
