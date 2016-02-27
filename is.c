/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoureu- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/27 09:29:11 by dmoureu-          #+#    #+#             */
/*   Updated: 2016/02/27 09:33:04 by dmoureu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
