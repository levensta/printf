/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: levensta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 16:40:00 by levensta          #+#    #+#             */
/*   Updated: 2020/12/13 20:44:32 by levensta         ###   ########.fr       */
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
		else
		pf->precis = 0;
	}
}

int	get_value(t_printf *pf)
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
				ft_putchar(format[i++]);
			if (format[i] == 0)
				break;
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
















// #include "ft_printf.h"
// #include <stdio.h>

// void	width_trim(char *format, int *i, t_printf *pf)
// {
// 	if (format[*i] == '*')
// 	{
// 		pf->width = va_arg(g_ptr, int);
// 		if (pf->width < 0)
// 		{
// 			pf->flag_minus = '-';
// 			pf->width *= -1;
// 		}
// 		(*i)++;
// 	}
// 	else if (format[*i] >= '0' && format[*i] <= '9')
// 	{
// 		pf->width = ft_atoi_w(&format[*i]);
// 		*i = *i + ft_nlen(ft_atoi_w(&format[*i]));
// 	}
// }

// void	precis_trim(char *format, int *i, t_printf *pf)
// {
// 	if (format[*i] == '.')
// 	{
// 		(*i)++;
// 		pf->is_precis = 1;
// 		if (format[*i] == '*')
// 		{
// 			pf->precis = va_arg(g_ptr, int); // обработать 0 и - в processor'e
// 			(*i)++;
// 		}
// 		else if (format[*i] >= '0' && format[*i] <= '9')
// 		{
// 			pf->precis = ft_atoi_w(&format[*i]);
// 			*i = *i + ft_nlen(ft_atoi_w(&format[*i]));
// 		}
// 		else
// 		pf->precis = 0;
// 	}
// }

// int	get_value(t_printf *pf)
// {
// 	if (pf->type == 'd')
// 		pf->values.di = va_arg(g_ptr, int);
// 	if (pf->type == 'i')
// 		pf->values.di = va_arg(g_ptr, int);
// 	if (pf->type == 'u')
// 		pf->values.u = va_arg(g_ptr, unsigned int);
// 	if (pf->type == 'c')
// 		pf->values.c = (char)va_arg(g_ptr, int);
// 	if (pf->type == 's')
// 		pf->values.s = va_arg(g_ptr, char*);
// 	if (pf->type == 'p')
// 		pf->values.p = va_arg(g_ptr, long long);
// 	return (0);
// }

// int	ft_parser(char *format, int tmp, t_printf *pf)
// {
// 	int i;

// 	i = tmp;
// 	i = ft_flgtrim(format, "0-", ++i, pf);
// 	width_trim(format, &i, pf);
// 	precis_trim(format, &i, pf);
// 	if ((i = ft_tptrim(format, "cspdiuxX%", i, pf)) == -1)
// 	{
// 		va_end(g_ptr);
// 		write(1, "WARNING", 7);
// 		return (0);
// 	}
// 	get_value(pf);
// 	return (1);
// }

// int	ft_printf(const char *format, ...)
// {
// 	t_printf	pf;
// 	int			i;
// 	char		*s;

// 	i = 0;
// 	g_count = 0;
// 	va_start(g_ptr, format);
// 	s = (char *)format;
// 	free_struct(&pf);
// 	while (format[i])
// 	{
// 		if (format[i] != '%')
// 		{
// 			while (format[i] != '%' && format[i])
// 				ft_putchar(format[i++]); // & ??
// 				// write(1, &format[i++], 1);
// 				// g_count++;
// 			if (format[i] == 0)
// 				break;
// 		}
// 		if ((ft_parser(s, i, &pf)) == 0)
// 			return (0);
// 		ft_processor(&pf);
// 		free_struct(&pf);
// 	}
// 	return (g_count);
// }

// int	main ()
// {
// 	// char	c = 'a';
// 	// int		d = 2147483647;
// 	// int		e = -2147483648;
// 	// int		i = 8;
// 	// int		j = -12;
// 	// int		k = 123456789;
// 	// int		l = 0;
// 	// int		m = -12345678;
// 	ft_printf("|%0*.*d|\n", 4, 0, -12);
// 	   printf("|%0*.*d|\n", 4, 0, -12);
// 	return(0);
// }