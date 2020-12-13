/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_value.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: levensta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 00:30:35 by levensta          #+#    #+#             */
/*   Updated: 2020/12/14 00:49:05 by levensta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		get_value(t_printf *pf)
{
	if (pf->type == 'd' || pf->type == 'i')
		pf->values.di = va_arg(g_ptr, int);
	if (pf->type == 'x' || pf->type == 'X')
		pf->values.xxp = va_arg(g_ptr, unsigned int);
	if (pf->type == 'p')
		pf->values.xxp = va_arg(g_ptr, unsigned long long);
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
