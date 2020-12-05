/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: levensta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 16:40:00 by levensta          #+#    #+#             */
/*   Updated: 2020/12/05 17:31:58 by levensta         ###   ########.fr       */
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
		specifier->values.c = (char)va_arg(g_ptr, int);
	if (specifier->type == 's')
	{
		// if (specifier->values.s)
		// 	free(specifier->values.s);
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
		else if (format[i] >= '0' && format[i] <= '9')
		{
			specifier.width = ft_atoi_w(&format[i]);
			i = i + ft_nlen(ft_atoi_w(&format[i]));
		}

//			Точность		//
		if (format[i] == '.')
		{
			i++;
			specifier.is_precis = 1;
			if (format[i] == '*')
			{
				specifier.precis = va_arg(g_ptr, int); // обработать 0 и - в processor'e
				i++;
			}
			else if (format[i] >= '0' && format[i] <= '9')
			{
				specifier.precis = ft_atoi_w(&format[i]);
				i = i + ft_nlen(ft_atoi_w(&format[i]));
			}
			else
			specifier.precis = 0;
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
	printf("precis: %d\n", specifier.precis);
	printf("is_pre: %d\n", specifier.is_precis);
	printf("%c\n", specifier.type);
	printf("%s\n", specifier.values.s);
	}
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_start(g_ptr, format);
	char *s = (char *)format;
	ft_parser(s);
	return (0);
}

int	main ()
{
	// char *s = "puk";
	ft_printf("text%+-*.*s", -1, -1, "lsgs");
	return(0);
}