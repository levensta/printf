/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: levensta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 16:40:00 by levensta          #+#    #+#             */
/*   Updated: 2020/11/29 23:32:29 by levensta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	ft_parser(char *format)
{
	t_printf	specifier;
	int		i;
	int		n;

	i = 0;
	specifier.flags = 0;
	while (format[i])
	{
		if (format[i] != '%')
		{
			i = tofind_c(format, '%');
			while (format[i] != '%')
				write(1, &format[i], 1);
		}
		i++;
		i = ft_strtrim(format, " 0+-#", i, &specifier); // flags
		if (format[i] == '*') // width
			n = va_arg(ptr, int);
		if (n < 0)
			n *= -1;
		//добавить минус во флаг

		specifier.width = ft_atoi(&format[i]);
		i = i + 1 + ft_nlen(ft_atoi(&format[i]));
		specifier.precis = ft_atoi(&format[i]);
		i = i + ft_nlen(ft_atoi(&format[i]));
	}
	// printf("%s\n", specifier.flags);
	// printf("%zu\n", specifier.width);
	// printf("%zu\n", specifier.precis);
	return (0);
}

int main()
{
	// char *s = "Hello!";
	// printf( "%.5s = %0*.*f", "value trash", 10, 5, M_PI );
	// printf("%0 *.18d",2147483647+10, 189);
	int x = 4;
	printf("%*.5d|\n",-10, x);
	return (0);
}