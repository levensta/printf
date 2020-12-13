/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: levensta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/13 23:57:33 by levensta          #+#    #+#             */
/*   Updated: 2020/12/14 00:25:40 by levensta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	*ft_memchr(const void *s, char c, size_t n)
{
	size_t	i;
	char	*str;

	if (n != 0)
	{
		i = -1;
		str = (char *)s;
		while (++i < n)
			if (str[i] == c)
				return (&str[i]);
	}
	return (NULL);
}
