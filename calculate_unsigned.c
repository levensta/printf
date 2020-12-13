/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_unsigned.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: levensta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/13 23:41:05 by levensta          #+#    #+#             */
/*   Updated: 2020/12/14 00:48:47 by levensta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	calculate_unsigned(t_printf *pf)
{
	int					len;
	unsigned long long	num;

	num = (pf->type == 'x' || pf->type == 'X' || pf->type == 'p') ? \
	pf->values.xxp : pf->values.u;
	len = ft_nlen_unsigned(pf, num);
	if (pf->type == 'p')
		len += 2;
	if (pf->is_precis == 1 && pf->precis >= pf->width && pf->precis >= len)
		pf->zero_count = pf->precis - len;
	else if (pf->width >= len && pf->is_precis && pf->precis > len)
	{
		pf->zero_count = pf->precis - len;
		pf->space_count = pf->width - pf->zero_count - len;
	}
	else if (pf->width > len)
		pf->space_count = pf->width - len;
	if (pf->is_precis && !(pf->precis) && !(num) && pf->width > 0)
		pf->space_count++;
}
