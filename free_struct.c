/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: levensta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 00:01:39 by levensta          #+#    #+#             */
/*   Updated: 2020/12/14 00:49:46 by levensta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	free_struct(t_printf *pf)
{
	pf->flag_zero = 0;
	pf->flag_minus = 0;
	pf->zero_count = 0;
	pf->space_count = 0;
	pf->width = -1;
	pf->precis = 0;
	pf->is_precis = 0;
	pf->type = 0;
	pf->values.di = 0;
	pf->values.u = 0;
	pf->values.c = 0;
	pf->values.s = 0;
}
