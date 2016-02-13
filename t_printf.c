/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_printf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoureu- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/13 19:24:55 by dmoureu-          #+#    #+#             */
/*   Updated: 2016/02/13 21:13:34 by dmoureu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_printf	*newprintf(char *format)
{
	t_printf	*pf;

	pf = (t_printf*)malloc(sizeof(t_printf));
	pf->format = ft_strdup(format);
	pf->opts = NULL;
	return (pf);
}


void	debugprintf(t_printf *pf)
{
	t_opts	*opts;

	ft_putendl("\n\nDebug printf :");
	ft_putstr("Chaine:[");
	ft_putstr(pf->format);
	ft_putendl("]");

	ft_putendl("opts:");
	opts = pf->opts;
	while (opts)
	{
		ft_putstr("[ opts->str:");
		ft_putstr(opts->str);
		ft_putstr(" type:");
		ft_putchar(opts->type);
		ft_putstr(" flag:");
		ft_putchar(opts->flag);
		ft_putendl("]");
		opts = opts->next;
	}
}
