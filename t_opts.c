#include "ft_printf.h"

void	initopts(t_opts *opts)
{
	opts->type = 0;
	opts->flag = 0;
	opts->width = 0;
	opts->width0 = 0;
	opts->precision = 0;
	opts->precisionn = 0;
	opts->modify = 0;

}

int istype(char c)
{
	char	*types = "diDuUcCsSoOxXp";
	if (ft_strchr(types, c))
		return (1);
	return (0);
}

int	isflag(char c)
{
	char	*flags = "-+ #";
	if (ft_strchr(flags, c))
			return (1);
	return (0);
}

void	analyseopts(t_opts *opts)
{
}

t_opts	*newopts(char *format)
{
	t_opts	*opts;
	int		length;
	char	*startopts;

	startopts = format;
	opts = (t_opts*)malloc(sizeof(t_opts));
	length = 0;
	while (!istype(*format))
	{
		length++;
		format++;
	}
	opts->str = ft_strnew(length + 1);
	opts->str = ft_strncpy(opts->str, startopts, length + 1);
	initopts(opts);
	opts->type = opts->str[length];
	opts->length = length;
	analyseopts(opts);
	opts->next = NULL;

	return (opts);
}

void	renderopts(t_opts *opts, va_list *pa)
{
	char	*s;
	char	c;
	int		n;

	if (opts->type == '%')
	{
		ft_putchar('%');
	}
	else if (opts->type == 'c')
	{
		c = va_arg(*pa, int);
		ft_putchar(c);
	}
	else if (opts->type == 'd')
	{
		n = va_arg(*pa, int);
		ft_putnbr(n);
	}
	else if (opts->type == 's')
	{
		s = va_arg(*pa, char *);
		ft_putstr(s);
	}
}

t_opts	*addopts(t_opts **lst, t_opts *new)
{
	t_opts	*beginlst;
	t_opts	*current;

	beginlst = *lst;
	current = beginlst;
	if (!*lst)
		beginlst = new;
	else
	{
		while (current->next)
			current = current->next;
		current->next = new;
	}
	return (beginlst);
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
