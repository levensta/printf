/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: levensta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 16:40:00 by levensta          #+#    #+#             */
/*   Updated: 2020/12/04 22:54:10 by levensta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	get_value(t_printf *specifier)
{
	if (specifier->type == 'd')
		specifier->values.di = va_arg(g_ptr, int);
	if (specifier->type == 'i')
		specifier->values.di = va_arg(g_ptr, int);
	if (specifier->type == 'u')
		specifier->values.u = va_arg(g_ptr, unsigned int);
	if (specifier->type == 'c')
		specifier->values.c = va_arg(g_ptr, char);
	if (specifier->type == 's')
	{
		// ??? //
		specifier->values.s = va_arg(g_ptr, char*);
	}
	if (specifier->type == 'p')
		specifier->values.p = va_arg(g_ptr, long long);
	return (0);
}

int	ft_parser(char *format)
{
	t_printf	specifier;
	int		i;

	i = 0;
	free_spec(&specifier);


	while (format[i])
	{

//			Считать текст до % или до \0
		if (format[i] != '%')
		{
			while (format[i] != '%' && format[i])
			{
				write(1, &format[i], 1);
				i++;
			}
			if (format[i] == 0)
				break;
		}
		i++;
		i = ft_flgtrim(format, " 0+-", i, &specifier); // flags

//			Ширина			 //
		if (format[i] == '*')
		{
			specifier.width = va_arg(g_ptr, int);
			if (specifier.width < 0)
			{
				specifier.flags = ft_strjoin(specifier.flags, "-");
				specifier.width *= -1;
			}
			i++;
		}
		else if ((specifier.width = ft_atoi_w(&format[i])) != -1)
			i = i + ft_nlen(ft_atoi_w(&format[i]));

//			Точность		//
		if (format[i] == '.')
		{
			i++;
			if (format[i] == '*')
			{
				specifier.precis = va_arg(g_ptr, int); // обработать 0 и - в processor'e
				i++;
			}
			else if ((specifier.precis = ft_atoi_w(&format[i])) != -1)
				i = i + ft_nlen(ft_atoi_w(&format[i]));
		}

//			записать тип
		if ((i = ft_tptrim(format, "cspdiuxX%", i, &specifier)) == -1)
		{
			va_end(g_ptr);
			write(1, "WARNING\n", 8);
			return (-1);
		}

//			взять значение va_arg
	get_value(&specifier);
	printf("%s\n", specifier.flags);
	printf("%d\n", specifier.width);
	printf("%d\n", specifier.precis);
	printf("%c\n", specifier.type);
	printf("%d\n", specifier.values.di);
	}
	return (0);
}