/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puts.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoureu- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 14:01:42 by dmoureu-          #+#    #+#             */
/*   Updated: 2016/02/25 23:05:01 by dmoureu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putwchar_fd(wchar_t chr, int fd)
{
	if (chr <= 0x7F)
		ft_putchar_fd(chr, fd);
	else if (chr <= 0x7FF)
	{
		ft_putchar_fd((chr >> 6) + 0xC0, fd);
		ft_putchar_fd((chr & 0x3F) + 0x80, fd);
	}
	else if (chr <= 0xFFFF)
	{
		ft_putchar_fd((chr >> 12) + 0xE0, fd);
		ft_putchar_fd(((chr >> 6) & 0x3F) + 0x80, fd);
		ft_putchar_fd((chr & 0x3F) + 0x80, fd);
	}
	else if (chr <= 0x10FFFF)
	{
		ft_putchar_fd((chr >> 18) + 0xF0, fd);
		ft_putchar_fd(((chr >> 12) & 0x3F) + 0x80, fd);
		ft_putchar_fd(((chr >> 6) & 0x3F) + 0x80, fd);
		ft_putchar_fd((chr & 0x3F) + 0x80, fd);
	}
}

int		ft_wcharlen(wchar_t c)
{
	if (c <= 0x7F)
		return (1);
	else if (c <= 0x7FF)
	{
		return (2);
	}
	else if (c <= 0xFFFF)
	{
		return (3);
	}
	else if (c <= 0x10FFFF)
	{
		return (4);
	}
	return (-1);
}

int		ft_wcslen(wchar_t *wstr)
{
	int	i;

	i = 0;
	while (wstr[i])
		i++;
	return (i);
}

int		ft_wstrlen(wchar_t *wstr)
{
	int	i;
	int	nbwrite;

	i = 0;
	nbwrite = 0;
	while (wstr[i])
	{
		nbwrite += ft_wcharlen(wstr[i]);
		i++;
	}
	return (nbwrite);
}

void	ft_putwchar(wchar_t c)
{
	ft_putwchar_fd(c, 1);
}

void	ft_putwstr(wchar_t *wstr)
{
	int	i;

	i = 0;
	while (wstr[i])
	{
		ft_putwchar(wstr[i]);
		i++;
	}
}

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
