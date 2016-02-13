#include "ft_printf.h"

void	initopts(t_opts *opts)
{
	opts->flag = 0;
	opts->width = 0;
	opts->width0 = 0;
}

int istype(char c)
{
	char	*types = "diDuUcCsSoOxXp";
	if (ft_strchr(types, c))
		return (1);
	return (0);
}

t_opts	*newopts(char *format)
{
	t_opts	*opts;
	int		length;

	opts = (t_opts*)malloc(sizeof(t_opts));
	length = 0;
	while (!istype(*format))
	{
		length++;
		format++;
	}
	return (opts);
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
