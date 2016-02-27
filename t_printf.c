/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_printf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoureu- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/13 19:24:55 by dmoureu-          #+#    #+#             */
/*   Updated: 2016/02/27 09:14:09 by dmoureu-         ###   ########.fr       */
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

void		printfclean(t_printf *pf)
{
	t_opts *opts;
	t_opts *c;

	opts = pf->opts;
	while (opts)
	{
		c = opts;
		opts = opts->next;
		if (c)
		{
			freestr(c->str);
			freestr(c->flags);
			freestr(c->modify);
			free(c);
		}
	}
	free(pf->format);
	free(pf);
}
