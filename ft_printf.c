/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: levensta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 20:12:17 by levensta          #+#    #+#             */
/*   Updated: 2020/12/13 21:44:32 by levensta         ###   ########.fr       */
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
// 	// int		d = 2147483647;
// 	// int		e = -2147483648;
// 	// int		i = 8;
// 	// int		j = -12;
// 	// int		k = 123456789;
// 	// int		l = 0;
// 	// int		m = -12345678;
// 	// int n = 4294;
// 	ft_printf("|%5%|\n");
// 	   printf("|%5%|\n");
// 	return(0);
// }