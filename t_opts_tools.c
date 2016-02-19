/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_opts_tools.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoureu- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 16:07:24 by dmoureu-          #+#    #+#             */
/*   Updated: 2016/02/19 16:37:53 by dmoureu-         ###   ########.fr       */
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
		//ft_strdel(&str);
		return (new);
	}
	else
		return (str);
}

char	*straddnchar(char *str, int way, int n, char c)
{
	int		i;
	int		length;
	char	*new;
	
	length = ft_strlen(str);
	new = ft_strnew(length + n);
	i = 0;
	if (way)
	{
		new = ft_strcpy(new, str);
		while (i < n)
		{
			new[length + i] = c;
			i++;
		}
	}
	else
	{
		while (i < n)
		{
			new[i] = c;
			i++;
		}
		new = ft_strcat(new, str);
	}
	//ft_strdel(&str);
	return (new);
}

char	*applywidth(t_opts *opts, char *str)
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
	length = ft_strlen(str);
	if (opts->width > length)
	{
		str = straddnchar(str, way, opts->width - length, c);
	}
	return (str);
}
