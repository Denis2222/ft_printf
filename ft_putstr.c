#include "ft_printf.h"

int	ft_putstr(char *str)
{
	int	length;

	length = ft_strlen(str);
	write(1, str, length);
	return (length);
}

