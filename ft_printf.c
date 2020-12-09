/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: levensta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 20:12:17 by levensta          #+#    #+#             */
/*   Updated: 2020/12/09 23:45:42 by levensta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	count_symbols = 0;
	va_start(g_ptr, format);
	char *s = (char *)format;
	ft_parser(s);
	return (count_symbols);
}

int	main ()
{
	// char *s = "puk";
	ft_printf("%*.*d|\n",-10, -7, -128);
	   printf("%*.*d|\n",-10, -7, -128);
	return(0);
}