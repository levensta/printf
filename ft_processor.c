/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_processor.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: levensta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 15:23:51 by levensta          #+#    #+#             */
/*   Updated: 2020/12/06 23:36:10 by levensta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*ft_itoa(int n)
{
	int		i;
	int		nb;
	char	*str;
	int		check_minus;

	i = 1;
	nb = n;
	check_minus = 1;
	while (n / 10 != 0 && i++)
		n = (n / 10);
	if (nb < 0 && i++)
		check_minus = -1;
	if (!(str = (char *)malloc((i + 1))))
		return (NULL);
	str[i] = '\0';
	while (i-- > 0)
	{
		str[i] = (nb % 10) * check_minus + '0';
		nb = nb / 10;
	}
	if (check_minus == -1)
		str[++i] = '-';
	return (str);
}

void	ft_putstr(char *s)
{
	int	i;

	i = 0;
	while (s && s[i] != '\0')
	{
		write(1, &s[i], 1);
		i++;
	}
}

int		ft_processor(t_printf *specifier)
{
	if (specifier->type == 'd' || specifier->type == 'i')
	{
		int len;
		int c;

		len = ft_nlen(specifier->values.di);
		if (specifier->precis < 0)
			specifier->precis = 0;
		c = (specifier->flag_zero && !(specifier->is_precis)) == 1 ? '0': ' '; // при флаге 0 заменяет пробелы нулями, если не указана точность
		if (specifier->is_precis == 1 && specifier->precis >= specifier->width
		&& specifier->precis >= len)
			specifier->zero_count = specifier->precis - len;
		else if (specifier->width >= len && specifier->is_precis && specifier->precis > len)
		{
			specifier->zero_count = specifier->precis - len;
			specifier->space_count = specifier->width - specifier->zero_count - len;
		}
		else if (specifier->width > len)
			specifier->space_count = specifier->width - len;
		
		while (specifier->space_count)
		{
			write(1, &c, 1);
			specifier->space_count--;
		}
		while (specifier->zero_count)
		{
			write(1, "0", 1);
			specifier->zero_count--;
		}
		ft_putstr(ft_itoa(specifier->values.di));
		
	}
	return (0);
}