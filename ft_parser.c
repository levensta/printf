/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: levensta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 16:40:00 by levensta          #+#    #+#             */
/*   Updated: 2020/12/03 23:30:03 by levensta         ###   ########.fr       */
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
	n = -1;
	free_spec(&specifier);
	while (format[i])
	{
		if (format[i] != '%')
		{
			i = tofind_c(format, '%');
			while (++n < i)
				write(1, &format[n], 1);

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
				specifier.precis = va_arg(g_ptr, int); // обработать 0 и - в processor
				i++;
			}
			else if ((specifier.precis = ft_atoi_w(&format[i])) != -1)
				i = i + ft_nlen(ft_atoi_w(&format[i]));
		}

//			записать тип и само значение 
		if ((i = ft_tptrim(format, "cspdiuxX%", i, &specifier)) == -1)
		{
			va_end(g_ptr);
			write(1, "WARNING\n", 8);
			return (-1);
		}
		else
		{
			va_arg(g_ptr,);
		}
		
		
	}
	printf("%s\n", specifier.flags);
	printf("%d\n", specifier.width);
	printf("%d\n", specifier.precis);
	printf("%c\n", specifier.type);
	return (0);
}