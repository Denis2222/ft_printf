#include "ft_printf.h"

int	ft_putnbr(int nb)
{
	int	w;

	w = 0;
	if (nb < 0)
	{
		w += ft_putchar('-');
		nb *= -1;
	}
	if (nb > 9)
	{
		w += ft_putnbr(nb / 10);
		w += ft_putnbr(nb % 10);
	}
	else
		w += ft_putchar('0' + nb);
	return (w);
}
