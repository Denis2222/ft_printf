#include "ft_printf.h"

void	initopts(t_opts *opts)
{
	opts->formatstart = 0;
	opts->formatend = 0;
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

void	analyseflags(t_opts *opts)
{
	char *str;
	str = opts->str;
	while (!isflag(*str) && *str)
		str++;
	if (isflag(*str))
		opts->flag = *str;
}

void	analysewidth(t_opts *opts)
{
	char	*str;
	int		startwidth;
	int		endwidth;
	int		i;
	char	*width;
	int		u;

//	ft_putstr("analyse opts");
	str = opts->str;
	i = 0;
	startwidth = 0;
	endwidth = 0;
	while (str[i] && str[i] != '.')
	{
		if (ft_isdigit(str[i]) && startwidth == 0)
		{
			startwidth = i;
			endwidth = i;
		}
		else if(ft_isdigit(str[i]))
			endwidth = i;
		i++;
	}

	width = (char*)malloc(sizeof(char) * ((endwidth - startwidth + 1) + 1));
	i = startwidth;
	u = 0;
	while(i <= endwidth)
	{
		width[u] = str[i];
		u++;
		i++;
	}
	width[u] = '\0';
	if (width[0] == '0')
		opts->width0 = 1;
	opts->width = ft_atoi(width);
	free(width);
//	ft_putstr("fin analyse opts");
}

void	analyseprecision(t_opts *opts)
{
	char	*str;
	int		nb;

	nb = 0;
	str = opts->str;
	if ((str = ft_strchr(str, '.')))
	{
		if ((nb = ft_atoi(++str)))
		{
			opts->precision = 1;
			opts->precisionn = nb;
		}
		else
			opts->precision = 1;
	}
}

void	analysemod(t_opts *opts)
{
	char	flags[6][4] = {"hh", "h", "l", "ll", "j", "z"};
	int		i;

	i = 0;
	(void)opts;
	while (flags[i] && i < 6 && !opts->modify)
	{
		//ft_putstr(flags[i]);
		if (ft_strstr(opts->str, flags[i]))
			opts->modify = ft_strdup(flags[i]);
		i++;
	}
}

void	analyseopts(t_opts *opts)
{
	analyseflags(opts);
	analysewidth(opts);
	analyseprecision(opts);
	analysemod(opts);
}

t_opts	*newopts(char *format, int pos)
{
	t_opts	*opts;
	int		length;
	char	*startopts;

//	ft_putstr("newopts");
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
	opts->formatstart = pos;
	opts->formatend = pos + length;
	opts->type = opts->str[length];
	opts->length = length;
	analyseopts(opts);
	opts->next = NULL;
//	ft_putstr("fin new opts");

	return (opts);
}

int	renderopts(t_opts *opts, va_list *pa)
{
	int		len;
	char	*s;
	wchar_t	*w;
	char	c;
	int		n;

//	ft_putstr("render opts");
	len = 0;
	if (opts->type == '%')
	{
		len++;
		ft_putchar('%');
	}
	else if (opts->type == 'c')
	{
		len++;
		c = va_arg(*pa, int);
		ft_putchar(c);
	}
	else if (opts->type == 'd')
	{
		n = va_arg(*pa, int);
		s = ft_itoa_base(n, 10);
		len += ft_strlen(s);
		ft_putstr(s);
	}
	else if (opts->type == 's')
	{
		s = (char *)va_arg(*pa, char *);
		ft_putstr(s);
		len += ft_strlen(s);
	}
	else if (opts->type == 'S')
	{
		w = va_arg(*pa, wchar_t *);
		len += ft_wstrlen(w);
		ft_putwstr(w);
	}
//	ft_putstr("fin render opts");

	return (len);
}

t_opts	*addopts(t_opts **lst, t_opts *new)
{
	t_opts	*beginlst;
	t_opts	*current;

//	ft_putstr("add opts");
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
//	ft_putstr("fin add opts");
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
