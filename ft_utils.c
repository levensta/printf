/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: levensta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 20:40:46 by levensta          #+#    #+#             */
/*   Updated: 2020/12/14 00:50:06 by levensta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_strlen(const char *str)
{
	int i;

	i = 0;
	while (str && str[i] != '\0')
		i++;
	return (i);
}

int		ft_nlen(int n)
{
	int		i;

	i = 1;
	while (n / 10 != 0 && i++)
		n = (n / 10);
	return (i);
}

int		ft_nlen_precis(const char *str)
{
	int i;
	int nb;

	i = 0;
	nb = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = (nb * 10) + (str[i] - '0');
		i++;
	}
	return (i);
}

int		ft_nlen_unsigned(t_printf *pf, unsigned long long n)
{
	int		i;
	char	*num;

	i = 1;
	num = 0;
	if (pf->type == 'u')
		while (n / 10 != 0 && i++)
			n = (n / 10);
	else
	{
		num = ft_itoa_16(pf->values.xxp, pf->type);
		i = ft_strlen(num);
	}
	if (num)
	{
		free(num);
		num = 0;
	}
	return (i);
}
