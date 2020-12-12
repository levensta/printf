/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: levensta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 20:12:17 by levensta          #+#    #+#             */
/*   Updated: 2020/12/12 20:30:06 by levensta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	g_count = 0;
	va_start(g_ptr, format);
	char *s = (char *)format;
	ft_parser(s);
	va_end(g_ptr);
	return (g_count);
}

// int	main ()
// {
// 	// char	c = 'a';
// 	// int		d = 2147483647;
// 	// int		e = -2147483648;
// 	// int		i = 8;
// 	// int		j = -12;
// 	// int		k = 123456789;
// 	// int		l = 0;
// 	// int		m = -12345678;
// 	ft_printf("|%d|\n", 255);
// 	   printf("|%d|\n", 255);
// 	return(0);
// }