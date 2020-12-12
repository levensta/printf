/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_processor.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: levensta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 15:23:51 by levensta          #+#    #+#             */
/*   Updated: 2020/12/12 20:29:55 by levensta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*ft_itoa_16(unsigned int n, char type)
{
	int				i;
	unsigned int	nb;
	char			*str;

	i = 1;
	nb = n;
	while ((n / 16 ) != 0 && i++)
		n = (n / 16);
	if (!(str = (char *)malloc((i + 1))))
		return (NULL);
	str[i] = '\0';
	while (i-- > 0)
	{
		if (nb % 16 < 10)
			str[i] = (nb % 16) + '0';
		else if (type == 'x')
			str[i] = (nb % 16) - 10 + ('a');
		else if (type == 'X')
			str[i] = (nb % 16) - 10 + ('A');
		nb = nb / 16;
	}
	return (str);
}

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

void	print_num(t_printf *pf)
{
	char	*num;

	num = 0;
	if (pf->type == 'x'|| pf->type == 'X')
	{
		num = ft_itoa_16(pf->values.xX, pf->type);
		ft_putstr(num);
	}
	else if (!(pf->is_precis && !(pf->precis) && !(pf->values.di)))
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

void	calculate_hex(t_printf *pf)
{
	int		len;

	len = ft_nlen(pf->values.xX);
	if (pf->is_precis == 1 && pf->precis >= pf->width && pf->precis >= len)
		pf->zero_count = pf->precis - len;
	else if (pf->width >= len && pf->is_precis && pf->precis > len)
	{
		pf->zero_count = pf->precis - len;
		pf->space_count = pf->width - pf->zero_count - len;
	}
	else if (pf->width > len) // > заменить на >= ??
		pf->space_count = pf->width - len;
	if (pf->is_precis && !(pf->precis) && !(pf->values.xX) && pf->width > 0) // частный случай
		pf->space_count++;
	if (pf->values.xX < 0 && pf->space_count > 0)
		pf->space_count--; // if (c == ' ')
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

void	print_hex(t_printf *pf, char c)
{
	if (pf->flag_minus)
	{
		put_precis(pf);
		print_num(pf);
		put_space(pf, c);
	}
	else
	{
		put_space(pf, c);
		put_precis(pf);
		print_num(pf);
	}
}

void	proc_num(t_printf *pf)
{
	int		c;

	if (pf->precis < 0)
		pf->is_precis = 0;
	if (pf->flag_minus || (pf->flag_zero && pf->is_precis))
		pf->flag_zero = 0;
	c = (!(pf->flag_minus) && pf->flag_zero && !(pf->is_precis)) ? '0' : ' ';
	if (pf->type == 'd' || pf->type == 'i')
	{
		calculate_int(pf);
		print_int(pf, c);
	}
	if (pf->type == 'x' || pf->type == 'X')
	{
		calculate_hex(pf);
		print_hex(pf, c);
	}
}

int		ft_processor(t_printf *pf)
{
	if (pf->type == 'd' || pf->type == 'i')
		proc_num(pf);
	if (pf->type == 'x' || pf->type == 'X')
		proc_num(pf);
	return (0);
}
