/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: levensta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/13 23:48:21 by levensta          #+#    #+#             */
/*   Updated: 2020/12/14 00:22:33 by levensta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
	g_count++;
}

void	ft_putstr(char *s)
{
	int	i;

	i = 0;
	while (s && s[i] != '\0')
	{
		ft_putchar(s[i]);
		i++;
	}
}

void	put_minus(t_printf *pf)
{
	ft_putchar('-');
	pf->values.di *= -1;
}

void	put_precis(t_printf *pf)
{
	while (pf->zero_count)
	{
		ft_putchar('0');
		pf->zero_count--;
	}
}

void	put_space(t_printf *pf, char c)
{
	while (pf->space_count)
	{
		ft_putchar(c);
		pf->space_count--;
	}
}
