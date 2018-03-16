/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 11:10:47 by gduval            #+#    #+#             */
/*   Updated: 2017/03/13 11:11:28 by gduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# define THERE_IS_NO_SPECIAL_CHAR format[j] != s &&
# define GLOBAL params->global

# include <stdarg.h>
# include <inttypes.h>
# include <wchar.h>
# include "../../includes/libft.h"

typedef struct	s_global
{
	char		type;
	int			i;
	int			count;
	int			max_count;
	uintmax_t	count_letters;
	int			activate_precision;
}				t_global;

typedef struct	s_printf
{
	int			hh;
	int			h;
	int			l;
	int			ll;
	int			j;
	int			z;
	int			hash;
	int			zero;
	int			minus;
	int			plus;
	int			blank;
	intmax_t	width;
	intmax_t	precision;
	t_global	*global;
}				t_printf;

int				ft_printf(const char *format, ...);
int				start_read(const char *format, t_printf *params, \
	t_global *global, va_list vl);
void			init_struct(t_printf *params, t_global *global);
t_global		*init_global(t_global *global);
int				count_params(const char *format);
char			is_a_type(const char c);
int				fill_params(const char **s, t_printf *params);
int				get_precision(char *string, t_printf *params);
char			*delete_precision(char *string, t_printf *params);
int				get_width(char *string, t_printf *params, va_list vl);
char			*add_plus(char *str, t_printf *params);
char			*add_hash(char *str, t_printf *params);
char			*add_space(char *str, t_printf *params);
char			*add_precision(char *str, t_printf *params);
wchar_t			*add_precision_unicode(wchar_t *str, t_printf *params);
char			*nb_precision(char *str, t_printf *params);
char			*width_gestion(char *str, t_printf *params);
wchar_t			*width_gestion_unicode(wchar_t *str, t_printf *params);
char			*special_width(char *str, t_printf *params);
char			*flags_gestion(va_list vl, t_printf *params);
char			*flags_gestion_unsigned(va_list vl, t_printf *params);
char			*flags_gestion_base(va_list vl, t_printf *params, int base);
char			*flags_gestionhexa(va_list vl, t_printf *params);
char			*flags_octal(va_list vl, t_printf *params);
void			print_param(va_list vl, t_printf *params);
void			print_hexa(va_list vl, t_printf *params);
void			print_string(va_list vl, t_printf *params);
void			print_octal(va_list vl, t_printf *params);
void			print_unsigned(va_list vl, t_printf *params);
void			print_unicode_char(va_list vl, t_printf *params);
int				ft_strwlenplus(wchar_t *str);
void			ft_putstri(const char *str, int len);
void			normalize_flags(t_printf *params);
void			ft_putwchar(wchar_t c, t_printf *params);
void			ft_putwcharstr(wchar_t *str, t_printf *params);
char			*ft_itoabase_max(intmax_t n, int base);
char			*ft_printhex(uintmax_t n, int base);
char			*ft_printoct_base(unsigned long long n, int base);
wchar_t			*ft_strwdup(const wchar_t *src);
wchar_t			*ft_strwjoin(wchar_t *s1, wchar_t *s2, int option);
size_t			ft_strwlen(const wchar_t *str);
wchar_t			*ft_strwsub(wchar_t const *s, unsigned int start, size_t len,
	int option);
intmax_t		ft_atoi_max(const char *str);
char			*ft_itoa_basemax(intmax_t n, int base);
char			*upper(char *str);
void			ft_exit(t_printf *params, t_global *global, va_list vl);
#endif
