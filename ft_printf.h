/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: levensta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 21:34:21 by levensta          #+#    #+#             */
/*   Updated: 2020/11/29 23:14:52 by levensta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <stdarg.h> 
# include <stdio.h>

va_list		ptr;

typedef struct	s_printf
{
	char	*lineup;
	char	*flags;
	int		width;
	int		precis;
	char	type;
}				t_printf;

size_t	ft_strlen(const char *str);
int		tofind_c(char *s, char c);
void	*ft_memchr(const void *s, int c, size_t n);
char	*ft_substr(char const *s, unsigned int start, int len);
int		ft_strtrim(char *s1, char *set, int i, t_printf *specifer);
int		ft_parser(char *format);
int		ft_atoi(const char *str);
int		ft_nlen(int n);

#endif