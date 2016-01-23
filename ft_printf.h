#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdarg.h>
# include <unistd.h>

int	ft_printf(char *format, ...);

int	ft_strlen(char *str);

int	ft_putchar(char c);
int	ft_putstr(char *str);
int	ft_putnbr(int nb);

#endif
