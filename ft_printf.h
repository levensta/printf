/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: levensta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 21:34:21 by levensta          #+#    #+#             */
/*   Updated: 2020/12/14 00:48:10 by levensta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

int			g_count;
va_list		g_ptr;

typedef struct	s_content
{
	int					di;
	unsigned int		u;
	unsigned long long	xxp;
	char				c;
	char				*s;
}				t_content;

typedef struct	s_printf
{
	char		flag_zero;
	char		flag_minus;
	int			width;
	int			precis;
	int			is_precis;
	char		type;
	t_content	values;
	int			zero_count;
	int			space_count;
}				t_printf;

int				ft_printf(const char *format, ...);
void			free_struct(t_printf *specifier);
int				ft_parsing(char *format, t_printf *pf);
int				get_value(t_printf *specifier);
int				get_specifier(char *format, int *i, t_printf *pf);
int				ft_flgtrim(char *s1, char *set, int i, t_printf *specifer);
int				ft_tptrim(char *s1, char *set, int i, t_printf *specifer);
void			width_trim(char *format, int *i, t_printf *specifier);
void			precis_trim(char *format, int *i, t_printf *specifier);
int				ft_nlen(int n);
int				ft_nlen_precis(const char *str);
size_t			ft_strlen(const char *str);
void			*ft_memchr(const void *s, char c, size_t n);
int				ft_atoi(const char *str);

int				ft_processor(t_printf *specifier);
void			proc_num(t_printf *pf);
void			proc_str(t_printf *pf);
void			proc_c(t_printf *pf);
void			calculate_int(t_printf *pf);
void			calculate_unsigned(t_printf *pf);
int				ft_nlen_unsigned(t_printf *pf, unsigned long long n);
void			print_num(t_printf *pf);
void			print_int(t_printf *pf, char c);
void			print_unsigned(t_printf *pf, char c);
void			print_str(t_printf *pf, int len);
char			*ft_itoa(int n);
char			*ft_itoa_16(unsigned long long n, char type);
void			ft_putstr(char *s);
void			ft_putchar(char c);
void			put_minus(t_printf *pf);
void			put_precis(t_printf *pf);
void			put_space(t_printf *pf, char c);
#endif
