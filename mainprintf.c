#include <stdio.h>
#include <stdarg.h>

void	myprintf(char *format, ...)
{
	va_list	pa;
	int		n;
	char	*s;
	char	c;
	float	f;

	va_start(pa, format);
	while (*format != '\0')
	{
		if (*format == '%')
		{
			if (*(++format) == '%')
			{
				putchar('%');
			}
			else if (*format == 'c')
			{
				c = va_arg(pa, int);
				printf("%c", c);
			}
			else if (*format == 'd')
			{
				n = va_arg(pa, int);
				printf("%d", n);
			}
			else if (*format == 'f')
			{
				f = va_arg(pa, double);
				printf("%f", f);
			}
			else if (*format == 's')
			{
				s = va_arg(pa, char *);
				printf("%s", s);
			}
		}
		else
			putchar(*format);
		format++;
	}
	va_end(pa);
}

int	main(void)
{
	myprintf("TEST %d ",4);
	return (0);
}
