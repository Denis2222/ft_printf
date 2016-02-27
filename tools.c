/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoureu- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 22:01:50 by dmoureu-          #+#    #+#             */
/*   Updated: 2016/02/27 05:30:19 by dmoureu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	freestr(char *str)
{
	if (*str)
		free(str);
}

void	freewstr(wchar_t *wstr)
{
	if (*wstr && ft_wstrlen(wstr) > 0)
		free(wstr);
}
