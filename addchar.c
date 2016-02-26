/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   addchar.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoureu- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/22 00:17:03 by dmoureu-          #+#    #+#             */
/*   Updated: 2016/02/26 04:44:17 by dmoureu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

wchar_t	*wstraddnchar(wchar_t *wstr, int way, int n, char c)
{
	int		i;
	int		length;
	wchar_t	*new;

	length = ft_wcslen(wstr);
	new = ft_wcsnew(length + n);
	i = 0;
	if (way)
	{
		new = ft_wcscpy(new, wstr);
		while (i < n)
		{
			new[length + i] = (wchar_t)c;
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
		new = ft_wcscat(new, wstr);
	}
	return (new);
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
	return (new);
}
