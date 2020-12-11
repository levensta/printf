/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: levensta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 20:12:17 by levensta          #+#    #+#             */
/*   Updated: 2020/12/11 22:09:15 by levensta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	g_count = 0;
	va_start(g_ptr, format);
	char *s = (char *)format;
	ft_parser(s);
	return (g_count);
}



// int	main ()
// {
// 	int		a = 19;
// 	int		b = 14;
// 	// char	c = 'a';
// 	// int		d = 2147483647;
// 	// int		e = -2147483648;
// 	// int		i = 8;
// 	// int		j = -12;
// 	// int		k = 123456789;
// 	// int		l = 0;
// 	// int		m = -12345678;
// 	ft_printf("|%*.*d| |%*.*d|\n", -a, b, -42, a, -b, 42);
// 	   printf("|%*.*d| |%*.*d|\n", -a, b, -42, a, -b, 42);
// 	return(0);
// }