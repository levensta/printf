/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: levensta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 16:40:00 by levensta          #+#    #+#             */
/*   Updated: 2020/12/13 22:21:10 by levensta         ###   ########.fr       */
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
			pf->precis = va_arg(g_ptr, int);
			(*i)++;
		}
		else if (format[*i] >= '0' && format[*i] <= '9')
		{
			pf->precis = ft_atoi_w(&format[*i]);
			*i = *i + ft_nlen_precis(&format[*i]);
		}
	}
}

int		get_value(t_printf *pf)
{
	if (pf->type == 'd' || pf->type == 'i')
		pf->values.di = va_arg(g_ptr, int);
	if (pf->type == 'x' || pf->type == 'X')
		pf->values.xXp = va_arg(g_ptr, unsigned int);
	if (pf->type == 'p')
		pf->values.xXp = va_arg(g_ptr, unsigned long long);
	if (pf->type == 'u')
		pf->values.u = va_arg(g_ptr, unsigned int);
	if (pf->type == 'c')
		pf->values.c = (char)va_arg(g_ptr, int);
	if (pf->type == 's')
		pf->values.s = va_arg(g_ptr, char*);
	if (pf->values.s == NULL)
		pf->values.s = "(null)";
	return (0);
}

int		ft_parser(char *format)
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
				ft_putchar(format[i++]);
			if (format[i] == 0)
				break ;
		}
		if (format[i + 1] == '%')
		{
			ft_putchar('%');
			i += 2;
			continue ;
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
		ft_processor(&pf);
		free_struct(&pf);
	}
	return (1);
}
