#include "ft_printf.h"

void	initopts(t_opts *opts)
{
	opts->flag = 0;
	opts->width = 0;
	opts->width0 = 0;
}

int	optsflag(t_opts *opts, char *str)
{
	if (*str == '-' || *str == '+' || *str == ' ' || *str == '#')
	{
		opts->flag = *str;
		return (1);
	}
	else
		return (0);
}
