/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_16.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: levensta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/13 23:53:27 by levensta          #+#    #+#             */
/*   Updated: 2020/12/14 00:21:34 by levensta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_itoa_16(unsigned long long n, char type)
{
	int					i;
	int					base;
	unsigned long long	nb;
	char				*str;

	i = 1;
	nb = n;
	base = (type == 'u') ? 10 : 16;
	while ((n / base) != 0 && i++)
		n = (n / base);
	if (!(str = (char *)malloc((i + 1))))
		return (NULL);
	str[i] = '\0';
	while (i-- > 0)
	{
		if (nb % base < 10)
			str[i] = (nb % base) + '0';
		else if (type == 'x' || type == 'p')
			str[i] = (nb % base) - 10 + ('a');
		else if (type == 'X')
			str[i] = (nb % base) - 10 + ('A');
		nb = nb / base;
	}
	return (str);
}
