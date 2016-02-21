/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_printf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoureu- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/13 19:24:55 by dmoureu-          #+#    #+#             */
/*   Updated: 2016/02/22 00:28:29 by dmoureu-         ###   ########.fr       */
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
		ft_putstr(" width:");
		ft_putnbr(opts->width);
		if (opts->width0)
			ft_putstr(" &0 ");
		if (opts->precision)
		{
			ft_putstr(" precision:");
			ft_putnbr(opts->precisionn);
		}
		if (opts->modify)
		{
			ft_putstr(" mod:");
			ft_putstr(opts->modify);
		}
		ft_putstr(" pos:");
		ft_putnbr(opts->formatstart);
		ft_putstr(" ");
		ft_putnbr(opts->formatend);
		ft_putendl("]");
		opts = opts->next;
	}
}
