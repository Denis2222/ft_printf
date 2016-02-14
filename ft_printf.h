#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"

int					ft_printf(char *format, ...);

typedef struct		s_opts
{
	char			*str;
	int				length;

	char			type;
	char			flag;
	int				width;
	int				width0;
	int				precision;
	int				precisionn;
	char			*modify;

	struct s_opts	*next;
}					t_opts;

t_opts				*newopts(char *format);
t_opts				*addopts(t_opts **lst, t_opts *new);
void				renderopts(t_opts *opts, va_list *pa);
void				initopts(t_opts *opts);
int					optsflag(t_opts *opts, char *str);

typedef struct		s_ftprintf
{
	char			*format;
	t_opts			*opts;
}					t_printf;

t_printf			*newprintf(char *format);
void	debugprintf(t_printf *pf);

int					choose(va_list *pa, char *format);

#endif
