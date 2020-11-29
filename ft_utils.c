/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: levensta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 20:40:46 by levensta          #+#    #+#             */
/*   Updated: 2020/11/29 22:42:07 by levensta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "ft_printf.h"

// char		*ft_strccpy(char *source, char c)
// {
// 	int		i;
// 	int		j;
// 	char	*dest;

// 	i = 0;
// 	j = 0;
// 	if (source == NULL)
// 		return (0);
// 	while (source[i] != c)
// 		i++;
// 	if (!(dest = malloc(i + 1)))
// 		return (NULL);
// 	while (source[j] != c)
// 	{
// 		dest[j] = source[j];
// 		j++;
// 	}
// 		dest[j] = '\0';
// 	return (dest);
// }

size_t	ft_strlen(const char *str)
{
	int i;

	i = 0;
	while (str && str[i] != '\0')
		i++;
	return (i);
}

int		tofind_c(char *s, char c)
{
	int	i;

	i = -1;
	if (s)
	{
		while (s[++i])
		{
			if (s[i] == c)
				return (i);
		}
	}
	return (-1);
}

char		*ft_strdup(const char *s1)
{
	size_t	i;
	char	*s2;

	i = 0;
	if (!(s2 = malloc((ft_strlen(s1) + 1) * sizeof(char))))
		return (NULL);
	while (s1[i] != '\0')
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}

char	*ft_substr(char const *s, unsigned int start, int len)
{
	char	*s2;
	int	i;

	i = 0;
	if (!s)
		return (NULL);
	if (s && start >= ft_strlen(s))
		return (ft_strdup(""));
	if (start + len > ft_strlen(s))
		len = ft_strlen(s) - start;
	if (!(s2 = malloc(len + 1 * sizeof(char))))
		return (NULL);
	while (i < len)
	{
		s2[i] = s[start];
		i++;
		start++;
	}
	s2[i] = '\0';
	return (s2);
}

void		*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;
	char	*str;
	char	ch;

	if (n != 0)
	{
		i = -1;
		str = (char *)s;
		ch = (char)c;
		while (++i < n)
			if (str[i] == ch)
				return (&str[i]);
	}
	return (NULL);
}


int			ft_strtrim(char *s1, char *set, int i, t_printf *specifer)
{
	unsigned int	start;

	start = i;
	if (!s1 || !set)
		return (-1);
	while (ft_memchr(set, s1[start], ft_strlen(set)))
	{
		start++;
		if (specifer->flags)
		{
			free(specifer->flags);
			specifer->flags = 0;
		}
		specifer->flags = ft_substr(s1, i, start - i);
	}

	return (start);
}

int			ft_atoi(const char *str)
{
	int i;
	int nb;
	int check_symbol;
	int amount;

	i = 0;
	nb = 0;
	check_symbol = 1;
	amount = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'
	|| str[i] == '\v' || str[i] == '\r' || str[i] == '\f')
		i++;
	if (str[i] == '+')
		i++;
	else if (str[i] == '-' && ++i)
		check_symbol = -1;
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = (nb * 10) + (str[i] - '0');
		amount += (nb == 0) ? 0 : 1;
		if (amount > 19)
			return ((check_symbol > 0) ? -1 : 0);
		i++;
	}
	return (nb * check_symbol);
}

int			ft_nlen(int n)
{
	int		i;
	int		nb;
	// int		check_minus;

	i = 1;
	nb = n;
	// check_minus = 1;
	while (n / 10 != 0 && i++)
		n = (n / 10);
	return (i);
}

// int		ft_printf(const char *s, ...)
// {
// 	va_list	ptr;
// 	int		num;

// 	va_start(ptr, s);
// 	num = va_arg(ptr, int);
// 	num = va_arg(ptr, int);