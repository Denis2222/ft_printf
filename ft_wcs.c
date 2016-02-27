/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wcs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoureu- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/22 00:14:23 by dmoureu-          #+#    #+#             */
/*   Updated: 2016/02/27 02:16:54 by dmoureu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

wchar_t	*ft_wcsnew(int n)
{
	wchar_t *wstr;

	wstr = (wchar_t *)malloc(sizeof(wchar_t *) * (++n));
	if (!wstr)
		return (NULL);
	while (n-- > 0)
		wstr[n] = '\0';
	return (wstr);
}

wchar_t	*ft_wcscpy(wchar_t *dest, wchar_t *src)
{
	int	pos;

	pos = 0;
	while (src[pos] != '\0')
	{
		dest[pos] = src[pos];
		pos++;
	}
	dest[pos] = '\0';
	return (dest);
}

wchar_t	*ft_wcsdup(wchar_t *src)
{
	wchar_t	*wstr;

	wstr = (wchar_t *)malloc(sizeof(wchar_t *) * (ft_wcslen(src) + 1));
	if (!wstr)
		return (NULL);
	ft_wcscpy(wstr, src);
	return (wstr);
}

wchar_t	*ft_wcscat(wchar_t *dest, const wchar_t *src)
{
	int	length;
	int	i;

	length = ft_wcslen(dest);
	i = 0;
	while (src[i])
	{
		dest[length + i] = src[i];
		i++;
	}
	dest[length + i] = '\0';
	return (dest);
}

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
