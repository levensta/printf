/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: levensta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 16:40:00 by levensta          #+#    #+#             */
/*   Updated: 2020/12/10 23:19:28 by levensta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

void	width_trim(char *format, int *i, t_printf *pf)
{
	if (format[*i] == '*')
	{
		pf->width = va_arg(g_ptr, int);
		if (pf->width < 0)
		{
			pf->flag_minus = '-';
			pf->width *= -1;
		}
		(*i)++;
	}
	else if (format[*i] >= '0' && format[*i] <= '9')
	{
		pf->width = ft_atoi_w(&format[*i]);
		*i = *i + ft_nlen(ft_atoi_w(&format[*i]));
	}
}

void	precis_trim(char *format, int *i, t_printf *pf)
{
	if (format[*i] == '.')
	{
		(*i)++;
		pf->is_precis = 1;
		if (format[*i] == '*')
		{
			pf->precis = va_arg(g_ptr, int); // обработать 0 и - в processor'e
			(*i)++;
		}
		else if (format[*i] >= '0' && format[*i] <= '9')
		{
			pf->precis = ft_atoi_w(&format[*i]);
			*i = *i + ft_nlen(ft_atoi_w(&format[*i]));
		}
		else
		pf->precis = 0;
	}
}

int	get_value(t_printf *pf)
{
	if (pf->type == 'd')
		pf->values.di = va_arg(g_ptr, int);
	if (pf->type == 'i')
		pf->values.di = va_arg(g_ptr, int);
	if (pf->type == 'u')
		pf->values.u = va_arg(g_ptr, unsigned int);
	if (pf->type == 'c')
		pf->values.c = (char)va_arg(g_ptr, int);
	if (pf->type == 's')
		pf->values.s = va_arg(g_ptr, char*);
	if (pf->type == 'p')
		pf->values.p = va_arg(g_ptr, long long);
	return (0);
}


int	ft_parser(char *format)
{
	t_printf	pf;
	int			i;

	i = 0;
	free_struct(&pf);
	while (format[i])
	{
		if (format[i] != '%')
		{
			while (format[i] != '%' && format[i])
				ft_putchar(format[i++]); // & ??
				// write(1, &format[i++], 1);
				// count_symbols++;
			if (format[i] == 0)
				break;
		}
		i = ft_flgtrim(format, "0-", ++i, &pf);
		width_trim(format, &i, &pf);
		precis_trim(format, &i, &pf);
		if ((i = ft_tptrim(format, "cspdiuxX%", i, &pf)) == -1)
		{
			va_end(g_ptr);
			write(1, "WARNING", 7);
			return (0);
		}
		get_value(&pf);
		// printf("flag:%c\n", pf.flag_minus);
		// printf("%d\n", pf.width);
		// printf("%d\n", pf.precis);
		// printf("%d\n", pf.is_precis);
		// printf("%c\n", pf.type);
		ft_processor(&pf);
	}
	free_struct(&pf);
	return (1);
}

// int	ft_printf(const char *format, ...)
// {
// 	count_symbols = 0;
// 	va_start(g_ptr, format);
// 	char *s = (char *)format;
// 	ft_parser(s);
// 	return (1);
// }