#include "ft_printf.h"

int	choose(va_list *pa, char *format)
{
	t_opts	opts;
	int		nb;
	int		n;
	char	*s;
	char	c;

	initopts(&opts);
	optsflag(&opts, format);
	//	(*format)++;
	nb = 0;
	if (*format == '%')
	{
		nb += ft_putchar('%');
		//(*format)++;
	}
	else if (*format == 'c')
	{
		c = va_arg(*pa, int);
		nb += ft_putchar(c);
		//(*format)++;
	}
	else if (*format == 'd')
	{
		n = va_arg(*pa, int);
		nb += ft_putnbr(n);
		//(*format)++;
	}
	else if (*format == 's')
	{
		s = va_arg(*pa, char *);
		nb += ft_putstr(s);
		//(*format)++;
	}
	return (nb);
}

int	ft_printf(char *format, ...)
{
	va_list	pa;
	int		nb;

	nb = 0;
	va_start(pa, format);
	while (*format != '\0')
	{
		if (*format == '%')
		{
			nb += choose(&pa, ++format);
		}
		else
			nb += ft_putchar(*format);
		format++;
	}
	va_end(pa);
	return (nb);
}
