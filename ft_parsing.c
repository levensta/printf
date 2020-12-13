/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: levensta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 16:40:00 by levensta          #+#    #+#             */
/*   Updated: 2020/12/14 00:32:00 by levensta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_parsing(char *format, t_printf *pf)
{
	int			i;

	i = 0;
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
		if ((get_specifier(format, &i, pf)) == 0)
			return (0);
		ft_processor(pf);
		free_struct(pf);
	}
	return (1);
}
