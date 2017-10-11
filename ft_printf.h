/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlegeay <mlegeay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/18 05:44:32 by mlegeay           #+#    #+#             */
/*   Updated: 2017/05/30 07:30:40 by mlegeay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <wchar.h>

char			g_buf[4096];
int				g_ibuf;

typedef struct	s_list
{
	char		spe;
	int			ret;
	char		*frmt;
	int			index;
	char		*result;
	wchar_t		*wresult;
	char		sign;
	int			flags[14];
}				t_list;

typedef struct	s_spec
{
	char		c;
	int			(*ptr)();
}				t_spec;

int				ft_printf(const char *format, ...);
void			ft_end(t_list *f);

int				ft_check(t_list *f);
void			ft_flags_init(t_list *f);
void			ft_check_flag(t_list *f);
void			ft_check_width(t_list *f);
void			ft_check_precision(t_list *f);
void			ft_check_modifier(t_list *f);

int				ft_isdigit(int c);
char			*ft_strsub(char const *s, unsigned int start, size_t len);
char			*ft_itoa_base(uintmax_t nbr, int base);
uintmax_t		ft_sign(t_list *f, intmax_t nbr);
size_t			ft_strlen(const char *str);
long			ft_atoi(const char *str);
char			*ft_strlwr(char *s1);

void			ft_putwchar(wchar_t wchar, t_list *f);
int				ft_wcharlen(wchar_t wchar);
size_t			ft_wbytelen(wchar_t *ws);
size_t			ft_wstrlen(wchar_t *ws);
char			*ft_wstrsub(wchar_t *ws, unsigned int start, size_t len);
char			*ft_strsub_with_free(char const *s, unsigned int start,
		size_t len);
char			*ft_wchar_in_char(wchar_t *ws);
int				ft_putwchar_in_char(wchar_t wchar, char *str, int i);

t_list			ft_init(void);
void			ft_init_specifiers(t_spec *specifiers);
void			ft_init_specifiers2(t_spec *specifiers);
int				ft_match_specifier(t_list *f, va_list *ap);

void			ft_apply_mask(t_list *f, int *mask);
int				ft_printf_char(t_list *f);
int				ft_printf_numb(t_list *f);

int				ft_printf_c(t_list *f, va_list *ap);
int				ft_printf_wc(t_list *f, va_list *ap);
int				ft_modifier_wc(t_list *f, va_list *ap);

int				ft_printf_s(t_list *f, va_list *ap);
int				ft_printf_ws(t_list *f, va_list *ap);

int				ft_printf_d(t_list *f, va_list *ap);
int				ft_printf_wd(t_list *f, va_list *ap);
char			*ft_modifier_d(t_list *f, va_list *ap);

int				ft_printf_o(t_list *f, va_list *ap);
int				ft_printf_u(t_list *f, va_list *ap);
char			*ft_modifier_u_o(t_list *f, va_list *ap);

int				ft_printf_wo(t_list *f, va_list *ap);
int				ft_printf_wu(t_list *f, va_list *ap);
char			*ft_modifier_wu_wo(t_list *f, va_list *ap);

int				ft_printf_x(t_list *f, va_list *ap);
int				ft_printf_wx(t_list *f, va_list *ap);
char			*ft_modifier_x(t_list *f, va_list *ap);

int				ft_printf_p(t_list *f, va_list *ap);
int				ft_printf_undefined(t_list *f);

void			ft_space_plus_sharp(t_list *f);
void			ft_sharp(t_list *f);
void			ft_precision_str(t_list *f);

void			ft_precision_wo_width(t_list *f);
void			ft_precision_numb(t_list *f, int len);
void			ft_zero_numb(t_list *f);
void			ft_minus_numb(t_list *f);
void			ft_width_numb(t_list *f);

void			ft_display(t_list *f);
void			ft_display_result(t_list *f);
void			ft_width_char(t_list *f);
void			ft_minus_char(t_list *f);
void			ft_zero_char(t_list *f);

void			ft_buf(char c, t_list *f);
void			ft_buf_null(t_list *f);
void			ft_display(t_list *f);
void			ft_setbuf(void);

#endif
