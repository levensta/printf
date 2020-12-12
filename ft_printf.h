/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: levensta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 21:34:21 by levensta          #+#    #+#             */
/*   Updated: 2020/12/12 20:26:10 by levensta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdio.h>

va_list		g_ptr;
int			g_count;

typedef struct	s_content
{
	int				di;
	unsigned int	u;
	char			c;
	char			*s;
	long long		p;
	unsigned int	xX;
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
size_t			ft_strlen(const char *str);
int				tofind_c(char *s, char c);
void			*ft_memchr(const void *s, char c, size_t n);
char			*ft_substr(char const *s, unsigned int start, int len);
int				ft_flgtrim(char *s1, char *set, int i, t_printf *specifer);
int				ft_tptrim(char *s1, char *set, int i, t_printf *specifer);
void	width_trim(char *format, int *i, t_printf *specifier);
void	precis_trim(char *format, int *i, t_printf *specifier);
// int		parser(char *format, int *i, t_printf *specifier);
char			*ft_strjoin(char *s1, char *s2);
int		ft_parser(char *format);
int				ft_atoi_w(const char *str);
int				ft_nlen(int n);
void			free_struct(t_printf *specifier);
int				get_value(t_printf *specifier);
int		ft_processor(t_printf *specifier);
void	ft_putstr(char *s);
void	ft_putchar(char c);
char		*ft_itoa(int n);
void	proc_num(t_printf *pf);
void	calculate_int(t_printf *pf);
void	put_minus(t_printf *pf);
void	put_precis(t_printf *pf);
void	put_space(t_printf *pf, char c);
void	print_num(t_printf *pf);
void	print_hex(t_printf *pf, char c);
char		*ft_itoa_16(unsigned int n, char type);
#endif
