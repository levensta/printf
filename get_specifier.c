/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_specifier.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: levensta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 00:29:06 by levensta          #+#    #+#             */
/*   Updated: 2020/12/14 00:46:38 by levensta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_flgtrim(char *s1, char *set, int i, t_printf *specifer)
{
	if (!s1 || !set)
		return (-1);
	while (ft_memchr(set, s1[i], ft_strlen(set)))
	{
		if (s1[i] == '0')
			specifer->flag_zero = 1;
		if (s1[i] == '-')
			specifer->flag_minus = 1;
		i++;
	}
	return (i);
}

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
		pf->width = ft_atoi(&format[*i]);
		*i = *i + ft_nlen(ft_atoi(&format[*i]));
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
			pf->precis = ft_atoi(&format[*i]);
			*i = *i + ft_nlen_precis(&format[*i]);
		}
	}
}

int		ft_tptrim(char *s1, char *set, int i, t_printf *specifer)
{
	if (!s1 || !set)
		return (-1);
	if (ft_memchr(set, s1[i], ft_strlen(set)))
	{
		specifer->type = s1[i];
		i++;
		return (i);
	}
	return (-1);
}

int		get_specifier(char *format, int *i, t_printf *pf)
{
	*i = ft_flgtrim(format, "0-", ++(*i), pf);
	width_trim(format, i, pf);
	precis_trim(format, i, pf);
	if ((*i = ft_tptrim(format, "cspdiuxX%", *i, pf)) == -1)
	{
		va_end(g_ptr);
		write(1, "WARNING", 7);
		return (0);
	}
	get_value(pf);
	return (1);
}
