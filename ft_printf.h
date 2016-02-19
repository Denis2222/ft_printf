/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoureu- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 14:01:51 by dmoureu-          #+#    #+#             */
/*   Updated: 2016/02/19 16:23:49 by dmoureu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

	int				formatstart;
	int				formatend;
	char			type;
	char			flag;
	int				width;
	int				width0;
	int				precision;
	int				precisionn;
	char			*modify;

	struct s_opts	*next;
}					t_opts;

t_opts				*newopts(char *format, int pos);
t_opts				*addopts(t_opts **lst, t_opts *new);
int					renderopts(t_opts *opts, va_list *pa);
void				initopts(t_opts *opts);
int					optsflag(t_opts *opts, char *str);

typedef struct		s_ftprintf
{
	char			*format;
	t_opts			*opts;
}					t_printf;

t_printf			*newprintf(char *format);
void				debugprintf(t_printf *pf);

int					choose(va_list *pa, char *format);

void				ft_putwchar_fd(wchar_t chr, int fd);
int					ft_wcharlen(wchar_t c);
int					ft_wstrlen(wchar_t *wstr);
void				ft_putwchar(wchar_t c);
void				ft_putwstr(wchar_t *wstr);

char				*ft_itoa_base(intmax_t value, int base);
char				*ft_uitoa_base(uintmax_t value, int base);

char				*ft_strminn(char *str, int size, int align, char c);
char				*ft_strmaxn(char *str, int size);

int					istype(char c);
int					isflag(char c);
void				analyseflags(t_opts *opts);
void				analysewidth(t_opts *opts);
void				analyseprecision(t_opts *opts);
void				analysemod(t_opts *opts);
void				analyseopts(t_opts *opts);
char				*render_opts_ptr(t_opts *opts, va_list *pa);
char				*render_opts_char(t_opts *opts, va_list *pa);
wchar_t				*render_opts_wchar(t_opts *opts, va_list *pa);
char				*render_opts_numeric_signed(t_opts *opts, va_list *pa);
char				*render_opts_numeric_unsigned(t_opts *opts, va_list *pa);

char				*addhexachar(char *str);
char				*applyprecision(t_opts *opts, char *str);
char				*applywidth(t_opts *opts, char *str);

#endif
