#include "ft_printf.h"

int	ft_printf(char *format, ...)
{
	va_list	pa;
	int		n;
	char	*s;
	char	c;
	float	f;
	int		nb;

	nb = 0;
	va_start(pa, format);
	while (*format != '\0')
	{
		if (*format == '%')
		{
			if (*(++format) == '%')
			{
				nb += ft_putchar('%');
			}
			else if (*format == 'c')
			{
				c = va_arg(pa, int);
				nb += ft_putchar(c);
			}
			else if (*format == 'd')
			{
				n = va_arg(pa, int);
				nb += ft_putnbr(n);
			}
			else if (*format == 'f')
			{
				f = va_arg(pa, double);
				printf("%f", f);
			}
			else if (*format == 's')
			{
				s = va_arg(pa, char *);
				nb += ft_putstr(s);
			}
		}
		else
			nb += ft_putchar(*format);
		format++;
	}
	va_end(pa);
	return (nb);
}

