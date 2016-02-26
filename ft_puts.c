/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puts.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoureu- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 14:01:42 by dmoureu-          #+#    #+#             */
/*   Updated: 2016/02/26 00:35:31 by dmoureu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


char *ft_strminn(char *str, int size, int align, char c)
{
	int		strlen;
	char	*out;
	int		i;

	i = 0;
	strlen = ft_strlen(str);
	if (strlen < size)
	{
		out = ft_strnew(size);
		if (align)
		{
			while (i < size - strlen)
				out[i++] = c;
			out = ft_strcat(out, str);
		}
		else
		{
			out = ft_strcat(out, str);
			i = ft_strlen(out);
			while (i < size)
				out[i++] = c;
		}
	}
	else
	{
		out = str;
	}
	return (out);
}

char *ft_strmaxn(char *str, int size)
{
	char *out;

	if ((int)ft_strlen(str) > size)
	{
		out = ft_strnew(size);
		ft_strncpy(out, str, size);
	}
	else
		out = str;
	return (out);
}
