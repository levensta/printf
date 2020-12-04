/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: levensta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 20:12:17 by levensta          #+#    #+#             */
/*   Updated: 2020/12/04 22:49:31 by levensta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_start(g_ptr, format);
	char *s = (char *)format;
	ft_parser(s);
	return (0);
}

int	main ()
{
	ft_printf("yes\n%0- +10.90d", 989);
	return(0);
}