/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: levensta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/13 23:56:40 by levensta          #+#    #+#             */
/*   Updated: 2020/12/14 00:42:11 by levensta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_atoi(const char *str)
{
	int i;
	int nb;
	int amount;

	i = 0;
	nb = 0;
	amount = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = (nb * 10) + (str[i] - '0');
		amount += (nb == 0) ? 0 : 1;
		if (amount > 19)
			return (-1);
		i++;
	}
	return (nb);
}
