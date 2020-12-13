/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_processor.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: levensta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 15:23:51 by levensta          #+#    #+#             */
/*   Updated: 2020/12/13 23:53:54 by levensta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	proc_num(t_printf *pf)
{
	int		c;

	if (pf->precis < 0)
		pf->is_precis = 0;
	if (pf->flag_minus || (pf->flag_zero && pf->is_precis))
		pf->flag_zero = 0;
	c = (!(pf->flag_minus) && pf->flag_zero && !(pf->is_precis)) ? '0' : ' ';
	if (pf->type == 'd' || pf->type == 'i')
	{
		calculate_int(pf);
		print_int(pf, c);
	}
	else if (pf->type == 'x' || pf->type == 'X' || \
	pf->type == 'u' || pf->type == 'p')
	{
		calculate_unsigned(pf);
		print_unsigned(pf, c);
	}
}

void	proc_str(t_printf *pf)
{
	int	len;

	if (pf->type == 's')
	{
		len = ft_strlen(pf->values.s);
		if (pf->precis < 0)
			pf->is_precis = 0;
		if (pf->is_precis && pf->precis < len)
			len = pf->precis;
		if (pf->width > len)
			pf->space_count = pf->width - len;
		print_str(pf, len);
	}
}

void	proc_c(t_printf *pf)
{
	int c;

	c = ' ';
	if (pf->type == '%')
	{
		pf->values.c = '%';
		c = (!(pf->flag_minus) && pf->flag_zero && !(pf->is_precis)) ? \
		'0' : ' ';
	}
	if (pf->width > 1)
		pf->space_count = pf->width - 1;
	if (pf->flag_minus)
	{
		ft_putchar(pf->values.c);
		put_space(pf, c);
	}
	else
	{
		put_space(pf, c);
		ft_putchar(pf->values.c);
	}
}

int		ft_processor(t_printf *pf)
{
	if (pf->type == 'd' || pf->type == 'i' || pf->type == 'p' \
	|| pf->type == 'x' || pf->type == 'X' || pf->type == 'u')
		proc_num(pf);
	if (pf->type == 's')
		proc_str(pf);
	if (pf->type == 'c' || pf->type == '%')
		proc_c(pf);
	return (0);
}
