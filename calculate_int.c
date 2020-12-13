/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: levensta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/13 23:40:48 by levensta          #+#    #+#             */
/*   Updated: 2020/12/14 00:46:27 by levensta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	calculate_int(t_printf *pf)
{
	int	len;
	int	num;

	num = pf->values.di;
	len = ft_nlen(num);
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
	if (num < 0 && pf->space_count > 0)
		pf->space_count--;
}
