/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: levensta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/13 23:38:49 by levensta          #+#    #+#             */
/*   Updated: 2020/12/14 00:50:14 by levensta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_num(t_printf *pf)
{
	char		*num;

	num = 0;
	if (pf->type == 'd' || pf->type == 'i')
	{
		if (!(pf->is_precis && !(pf->precis) && !(pf->values.di)))
			num = ft_itoa(pf->values.di);
	}
	else if (pf->type == 'x' || pf->type == 'X' || pf->type == 'p')
	{
		if (!(pf->is_precis && !(pf->precis) && !(pf->values.xxp)))
			num = ft_itoa_16(pf->values.xxp, pf->type);
	}
	else if (pf->type == 'u')
	{
		if (!(pf->is_precis && !(pf->precis) && !(pf->values.u)))
			num = ft_itoa_16(pf->values.u, pf->type);
	}
	ft_putstr(num);
	if (num)
	{
		free(num);
		num = 0;
	}
}

void	print_int(t_printf *pf, char c)
{
	if (pf->flag_minus)
	{
		if (pf->values.di < 0)
			put_minus(pf);
		put_precis(pf);
		if (pf->values.di == -2147483648)
			ft_putstr("2147483648");
		else
			print_num(pf);
		put_space(pf, c);
	}
	else
	{
		if (pf->values.di < 0 && pf->flag_zero)
			put_minus(pf);
		put_space(pf, c);
		if (pf->values.di < 0 && !(pf->flag_zero))
			put_minus(pf);
		put_precis(pf);
		if (pf->values.di == -2147483648)
			ft_putstr("2147483648");
		else
			print_num(pf);
	}
}

void	print_unsigned(t_printf *pf, char c)
{
	if (pf->flag_minus)
	{
		if (pf->type == 'p')
			ft_putstr("0x");
		else
			put_precis(pf);
		print_num(pf);
		put_space(pf, c);
	}
	else
	{
		put_space(pf, c);
		if (pf->type == 'p')
			ft_putstr("0x");
		else
			put_precis(pf);
		print_num(pf);
	}
}

void	print_str(t_printf *pf, int len)
{
	int	i;

	i = 0;
	if (pf->flag_minus)
	{
		while (pf->values.s[i] && i < len)
		{
			ft_putchar(pf->values.s[i]);
			i++;
		}
		put_space(pf, ' ');
	}
	else
	{
		put_space(pf, ' ');
		while (pf->values.s[i] && i < len)
		{
			ft_putchar(pf->values.s[i]);
			i++;
		}
	}
}
