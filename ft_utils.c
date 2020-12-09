/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: levensta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 20:40:46 by levensta          #+#    #+#             */
/*   Updated: 2020/12/09 22:20:56 by levensta         ###   ########.fr       */
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

void		*ft_memchr(const void *s, char c, size_t n)
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


int			ft_flgtrim(char *s1, char *set, int i, t_printf *specifer)
{
	if (!s1 || !set)
		return (-1);
	while (ft_memchr(set, s1[i], ft_strlen(set)))
	{
		if (s1[i] == '0')
			specifer->flag_zero = 1;
		if (s1[i] == '-')
			specifer->flag_minus = 1;
		i++;
	}
	return (i);
}

int			ft_tptrim(char *s1, char *set, int i, t_printf *specifer) // доделать
{
	if (!s1 || !set)
		return (-1);
	if (ft_memchr(set, s1[i], ft_strlen(set)))
	{
		specifer->type = s1[i];
		i++;
		return (i);
	}
	return (-1);
}

int			ft_atoi_w(const char *str)
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

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	if (!(str = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char))))
		return (NULL);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j])
		str[i++] = s2[j++];
	str[i] = '\0';
	free(s1);
	return (str);
}

int			ft_nlen(int n)
{
	int		i;
	int		nb;
	// int		check_minus;

	i = 1;
	nb = n;
	// if (n < 0)
	// 	i++;
	while (n / 10 != 0 && i++)
		n = (n / 10);
	return (i);
}

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
	pf->values.p = 0;
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
	count_symbols++;
}


// int		ft_printf(const char *s, ...)
// {
// 	va_list	ptr;
// 	int		num;

// 	va_start(ptr, s);
// 	num = va_arg(ptr, int);
// 	num = va_arg(ptr, int);