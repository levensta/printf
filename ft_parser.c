/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: levensta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 16:40:00 by levensta          #+#    #+#             */
/*   Updated: 2020/12/06 23:35:20 by levensta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "dwayne_johnson.h"
#include <stdio.h>

void	width_trim(char *format, int *i, t_printf *specifier)
{
	if (format[*i] == '*')
	{
		specifier->width = va_arg(g_ptr, int);
		if (specifier->width < 0)
		{
			specifier->flag_minus = '-';
			specifier->width *= -1;
		}
		(*i)++;
	}
	else if (format[*i] >= '0' && format[*i] <= '9')
	{
		specifier->width = ft_atoi_w(&format[*i]);
		*i = *i + ft_nlen(ft_atoi_w(&format[*i]));
	}
}

void	precis_trim(char *format, int *i, t_printf *specifier)
{
	if (format[*i] == '.')
	{
		(*i)++;
		specifier->is_precis = 1;
		if (format[*i] == '*')
		{
			specifier->precis = va_arg(g_ptr, int); // обработать 0 и - в processor'e
			(*i)++;
		}
		else if (format[*i] >= '0' && format[*i] <= '9')
		{
			specifier->precis = ft_atoi_w(&format[*i]);
			*i = *i + ft_nlen(ft_atoi_w(&format[*i]));
		}
		else
		specifier->precis = 0;
	}
}

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
		specifier->values.s = va_arg(g_ptr, char*);
	if (specifier->type == 'p')
		specifier->values.p = va_arg(g_ptr, long long);
	return (0);
}


int	ft_parser(char *format)
{
	t_printf	specifier;
	int			i;

	i = 0;
	free_struct(&specifier);
	while (format[i])
	{
		if (format[i] != '%')
		{
			while (format[i] != '%' && format[i])
				write(1, &format[i++], 1);
			if (format[i] == 0)
				break;
		}
		i = ft_flgtrim(format, "0-", ++i, &specifier);
		width_trim(format, &i, &specifier);
		precis_trim(format, &i, &specifier);
		if ((i = ft_tptrim(format, "cspdiuxX%", i, &specifier)) == -1)
		{
			va_end(g_ptr);
			print_dwayne();
			return (0);
		}
		get_value(&specifier);
		printf("flag:%c\n", specifier.flag_minus);
		printf("%d\n", specifier.width);
		printf("%d\n", specifier.precis);
		printf("%d\n", specifier.is_precis);
		printf("%c\n", specifier.type);
		ft_processor(&specifier);
	}
	free_struct(&specifier);
	return (1);
}

int	ft_printf(const char *format, ...)
{
	va_start(g_ptr, format);
	char *s = (char *)format;
	ft_parser(s);
	return (1);
}

int	main ()
{
	// char *s = "puk";
	ft_printf("%0*.5d\n", 40, 333);
	   printf("%0*.5d\n", 40, 333);
	return(0);
}