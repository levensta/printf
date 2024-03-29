/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: levensta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 20:12:17 by levensta          #+#    #+#             */
/*   Updated: 2020/12/14 00:44:24 by levensta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char *format, ...)
{
	char		*s;
	t_printf	pf;

	g_count = 0;
	s = (char *)format;
	va_start(g_ptr, format);
	free_struct(&pf);
	if ((ft_parsing(s, &pf)) == 0)
		return (0);
	va_end(g_ptr);
	return (g_count);
}
