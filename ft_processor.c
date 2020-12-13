/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_processor.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: levensta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 15:23:51 by levensta          #+#    #+#             */
/*   Updated: 2020/12/13 21:49:51 by levensta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*ft_itoa_16(unsigned long long n, char type)
{
	int					i;
	int					base;
	unsigned long long	nb;
	char				*str;

	i = 1;
	nb = n;
	base = (type == 'u') ? 10 : 16;
	while ((n / base ) != 0 && i++)
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
	char		*num;

	num = 0;
	if (pf->type == 'd' || pf->type == 'i')
	{
		if (!(pf->is_precis && !(pf->precis) && !(pf->values.di)))
			num = ft_itoa(pf->values.di);
	}
	else if (pf->type == 'x' || pf->type == 'X' || pf->type == 'p')
	{
		if (!(pf->is_precis && !(pf->precis) && !(pf->values.xXp)))
			num = ft_itoa_16(pf->values.xXp, pf->type);
	}
	else if (pf->type == 'u')
	{
		if (!(pf->is_precis && !(pf->precis) && !(pf->values.u)))
			num = ft_itoa_16(pf->values.u, pf->type);
	}
	ft_putstr(num);
	if (num)
	{
		free(num);
		num = 0;
	}
}

// void	calculate_int(t_printf *pf)
// {
// 	int		len;

// 	len = ft_nlen(pf->values.di);
// 	if (pf->is_precis == 1 && pf->precis >= pf->width && pf->precis >= len)
// 		pf->zero_count = pf->precis - len;
// 	else if (pf->width >= len && pf->is_precis && pf->precis > len)
// 	{
// 		pf->zero_count = pf->precis - len;
// 		pf->space_count = pf->width - pf->zero_count - len;
// 	}
// 	else if (pf->width > len) // > заменить на >= ??
// 		pf->space_count = pf->width - len;
// 	if (pf->is_precis && !(pf->precis) && !(pf->values.di) && pf->width > 0) // частный случай
// 		pf->space_count++;
// 	if (pf->values.di < 0 && pf->space_count > 0)
// 		pf->space_count--; // if (c == ' ')
// }

void	calculate_int(t_printf *pf)
{
	int	len;
	int	num;

	num = pf->values.di;
	len = ft_nlen(num);
	if (pf->is_precis == 1 && pf->precis >= pf->width && pf->precis >= len)
		pf->zero_count = pf->precis - len;
	else if (pf->width >= len && pf->is_precis && pf->precis > len)
	{
		pf->zero_count = pf->precis - len;
		pf->space_count = pf->width - pf->zero_count - len;
	}
	else if (pf->width > len) // > заменить на >= ??
		pf->space_count = pf->width - len;
	if (pf->is_precis && !(pf->precis) && !(num) && pf->width > 0) // частный случай
		pf->space_count++;
	if (num < 0 && pf->space_count > 0)
		pf->space_count--; // if (c == ' ')
}

void	calculate_unsigned(t_printf *pf)
{
	int					len;
	unsigned long long	num;

	num = (pf->type == 'x' || pf->type == 'X' || pf->type == 'p') ? \
	pf->values.xXp : pf->values.u;
	len = ft_nlen_unsigned(pf, num);
	if (pf->type == 'p')
		len += 2;
	if (pf->is_precis == 1 && pf->precis >= pf->width && pf->precis >= len)
		pf->zero_count = pf->precis - len;
	else if (pf->width >= len && pf->is_precis && pf->precis > len)
	{
		pf->zero_count = pf->precis - len;
		pf->space_count = pf->width - pf->zero_count - len;
	}
	else if (pf->width > len) // > заменить на >= ??
		pf->space_count = pf->width - len;
	if (pf->is_precis && !(pf->precis) && !(num) && pf->width > 0) // частный случай
		pf->space_count++;
	// if (num < 0 && pf->space_count > 0)
	// 	pf->space_count--; // if (c == ' ')
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

void	print_unsigned(t_printf *pf, char c)
{
	if (pf->flag_minus)
	{
		if (pf->type == 'p')
			ft_putstr("0x");
		else
			put_precis(pf);
		print_num(pf);
		put_space(pf, c);
	}
	else
	{
		put_space(pf, c);
		if (pf->type == 'p')
			ft_putstr("0x");
		else
			put_precis(pf);
		print_num(pf);
	}
}

void	print_str(t_printf *pf, int len)
{
	int	i;

	i = 0;
	if (pf->flag_minus)
	{
		while (pf->values.s[i] && i < len)
		{
			ft_putchar(pf->values.s[i]);
			i++;
		}
		put_space(pf, ' ');
	}
	else
	{
		put_space(pf, ' ');
		while (pf->values.s[i] && i < len)
		{
			ft_putchar(pf->values.s[i]);
			i++;
		}
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
	else if (pf->type == 'x' || pf->type == 'X' || \
	pf->type == 'u' || pf->type == 'p')
	{
		calculate_unsigned(pf);
		print_unsigned(pf, c);
	}
}

void	proc_str(t_printf *pf)
{
	int	len;

	if (pf->type == 's')
	{
		len = ft_strlen(pf->values.s);
		if (pf->precis < 0)
			pf->is_precis = 0;
		if (pf->is_precis && pf->precis < len)
			len = pf->precis;
		if (pf->width > len)
			pf->space_count = pf->width - len;
		print_str(pf, len);
	}
}

void	proc_c(t_printf *pf)
{
	int c;

	c = ' ';
	if (pf->type == '%')
	{
		pf->values.c = '%';
		c = (!(pf->flag_minus) && pf->flag_zero && !(pf->is_precis)) ? '0' : ' ';
	}
	if (pf->width > 1)
		pf->space_count = pf->width - 1;
	if (pf->flag_minus)
	{
		ft_putchar(pf->values.c);
		put_space(pf, c);
	}
	else
	{
		put_space(pf, c);
		ft_putchar(pf->values.c);
	}
}

int		ft_processor(t_printf *pf)
{
	if (pf->type == 'd' || pf->type == 'i' || pf->type == 'p' \
	|| pf->type == 'x' || pf->type == 'X' || pf->type == 'u')
		proc_num(pf);
	if (pf->type == 's')
		proc_str(pf);
	if (pf->type == 'c' || pf->type == '%')
		proc_c(pf);
	return (0);
}
