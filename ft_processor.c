/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_processor.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: levensta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 15:23:51 by levensta          #+#    #+#             */
/*   Updated: 2020/12/11 21:10:56 by levensta         ###   ########.fr       */
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
		g_count++;
	}
}

void	put_minus(t_printf *pf)
{
	ft_putchar('-');
	pf->values.di *= -1;
}

void	print_precis(t_printf *pf)
{
	while (pf->zero_count)
	{
		ft_putchar('0');
		pf->zero_count--;
	}
}

void	print_space(t_printf *pf, char c)
{
	while (pf->space_count)
	{
		ft_putchar(c);
		pf->space_count--;
	}
}

void	print_num(t_printf *pf)
{
	char	*num;
	
	num = 0;
	if (!(pf->is_precis && !(pf->precis) && !(pf->values.di)))
	{
		num = ft_itoa(pf->values.di);
		ft_putstr(num);
	}
	if (num)
	{
		free(num);
		num = 0;
	}
}

void	calculate_int(t_printf *pf)
{
	int		len;

	len = ft_nlen(pf->values.di);
	if (pf->is_precis == 1 && pf->precis >= pf->width && pf->precis >= len)
		pf->zero_count = pf->precis - len;
	else if (pf->width >= len && pf->is_precis && pf->precis > len)
	{
		pf->zero_count = pf->precis - len;
		pf->space_count = pf->width - pf->zero_count - len;
	}
	else if (pf->width > len) // > заменить на >= ??
		pf->space_count = pf->width - len;
	if (pf->is_precis && !(pf->precis) && !(pf->values.di) && pf->width > 0) // частный случай
		pf->space_count++;
	if (pf->values.di < 0 && pf->space_count > 0)
		pf->space_count--; // if (c == ' ')
}

void	proc_int(t_printf *pf)
{
	int		c;

	if (pf->precis < 0)
		pf->is_precis = 0;
	if (pf->flag_minus || (pf->flag_zero && pf->is_precis))
		pf->flag_zero = 0;
	c = (!(pf->flag_minus) && pf->flag_zero && !(pf->is_precis)) == 1 ? '0': ' ';
	calculate_int(pf);

	if (pf->flag_minus)
	{
		if (pf->values.di < 0)
			put_minus(pf);
		print_precis(pf);
		if (pf->values.di == -2147483648)
			ft_putstr("2147483648");
		else
			print_num(pf);
		print_space(pf, c);
	}
	else
	{
		if (pf->values.di < 0 && pf->flag_zero)
			put_minus(pf);
		print_space(pf, c);
		if (pf->values.di < 0 && !(pf->flag_zero))
			put_minus(pf);
		print_precis(pf);
		if (pf->values.di == -2147483648)
			ft_putstr("2147483648");
		else
			print_num(pf);
	}
}

int		ft_processor(t_printf *pf)
{
	if (pf->type == 'd' || pf->type == 'i')
		proc_int (pf);
	return (0);
}