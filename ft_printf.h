/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoureu- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 14:01:51 by dmoureu-          #+#    #+#             */
/*   Updated: 2016/02/27 04:43:46 by dmoureu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <wchar.h>
# include "libft/libft.h"

int					ft_printf(char *format, ...);

typedef struct		s_opts
{
	char			*str;
	int				length;
	int				formatstart;
	int				formatend;

	char			type;
	char			*flags;
	int				width;
	int				precision;
	int				precisionn;
	char			*modify;

	struct s_opts	*next;
}					t_opts;

t_opts				*newopts(char *format, int pos, va_list *pa);
t_opts				*addopts(t_opts **lst, t_opts *new);
int					renderopts(t_opts *opts, va_list *pa);
void				initopts(t_opts *opts, char *startopts);
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
int					ft_wcslen(wchar_t *wstr);
int					ft_wstrlen(wchar_t *wstr);
wchar_t				*ft_wcsnew(int n);
wchar_t				*ft_wcscpy(wchar_t *dest, wchar_t *src);
wchar_t				*ft_wcsdup(wchar_t *src);
wchar_t				*ft_wcscat(wchar_t *dest, const wchar_t *src);

void				ft_putwchar(wchar_t c);
void				ft_putwstr(wchar_t *wstr);

char				*ft_itoa_base(intmax_t value, int base);
char				*ft_uitoa_base(uintmax_t value, int base);

char				*ft_strminn(char *str, int size, int align, char c);
char				*ft_strmaxn(char *str, int size);

int					issigned(t_opts *opts);
int					isunsigned(t_opts *opts);
int					iswchar(t_opts *opts);
int					ischar(t_opts *opts);
int					isptr(t_opts *opts);

int					istype(char c);
int					isflag(char c);
int					ismod(char c);

int					isocta(t_opts *opts);
int					ishexa(t_opts *opts);

void				analyseflags(t_opts *opts);
void				analysewidth(t_opts *opts, va_list *pa);
void				analyseprecision(t_opts *opts, va_list *pa);
void				analysemod(t_opts *opts);
void				analyseopts(t_opts *opts, va_list *pa);
char				*render_opts_ptr(t_opts *opts, va_list *pa);
char				*render_opts_char(t_opts *opts, va_list *pa);
wchar_t				*render_opts_wchar(t_opts *opts, va_list *pa);
char				*render_opts_numeric_signed(t_opts *opts, va_list *pa);
char				*render_opts_numeric_unsigned(t_opts *opts, va_list *pa);
char				*render_opts_error(t_opts *opts, va_list *pa, char *str);

char				*straddnchar(char *str, int way, int n, char c);
wchar_t				*wstraddnchar(wchar_t *wstr, int way, int n, char c);

char				*addhexachar(char *str, int ishexa);
char				*applyflag(t_opts *opts, char *str);
char				*applyprecision(t_opts *opts, char *str);
wchar_t				*applyprecisionwchar(t_opts *opts, wchar_t *str);
char				*applywidth(t_opts *opts, char *str);
wchar_t				*applywidthwchar(t_opts *opts, wchar_t *wstr);

void				freestr(char *str);
void				freewstr(wchar_t *wstr);
void				printfclean(t_printf *pf);

#endif
