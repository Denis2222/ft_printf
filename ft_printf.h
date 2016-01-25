#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct	s_printf_option
{
	char		flag;

	int			width;
	int			width0;

	int			precision;
	int			precisionn;

	char		modify;

	char		type;
}				t_opts;

int	ft_printf(char *format, ...);

int	ft_strlen(char *str);

int	ft_putchar(char c);
int	ft_putstr(char *str);
int	ft_putnbr(int nb);

void	initopts(t_opts *opts);
int		optsflag(t_opts *opts, char *str);


#endif
