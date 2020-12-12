#include <stdio.h>
#include <math.h>
#include "ft_printf.h"
// #include "ft_printf.h"

// int			ft_atoi_w(const char *str)
// {
// 	int i;
// 	int nb;
// 	int check_symbol;
// 	int amount;

// 	i = 0;
// 	nb = 0;
// 	check_symbol = 1;
// 	amount = 0;
// 	if (str[i] == '+')
// 		i++;
// 	else if (str[i] == '-' && ++i)
// 		check_symbol = -1;
// 	while (str[i] >= '0' && str[i] <= '9')
// 	{
// 		nb = (nb * 10) + (str[i] - '0');
// 		amount += (nb == 0) ? 0 : 1;
// 		if (amount > 19)
// 			return ((check_symbol > 0) ? -1 : 0);
// 		i++;
// 	}
// 	return (nb * check_symbol);
// }

// char		*ft_itoa(int n)
// {
// 	int		i;
// 	int		nb;
// 	char	*str;
// 	int		check_minus;

// 	i = 1;
// 	nb = n;
// 	check_minus = 1;
// 	while (n / 10 != 0 && i++)
// 		n = (n / 10);
// 	if (nb < 0 && i++)
// 		check_minus = -1;
// 	if (!(str = (char *)malloc((i + 1))))
// 		return (NULL);
// 	str[i] = '\0';
// 	while (i-- > 0)
// 	{
// 		str[i] = (nb % 10) * check_minus + '0';
// 		nb = nb / 10;
// 	}
// 	if (check_minus == -1)
// 		str[++i] = '-';
// 	return (str);
// }

// void		check_hex(unsigned int *nb, int *i, char *str, const char *radix)
// {
// 	if (*nb % 16 == 10)
// 		str[*i] = radix[0];
// 	else if (*nb % 16 == 11)
// 		str[*i] = radix[1];
// 	else if (*nb % 16 == 12)
// 		str[*i] = radix[2];
// 	else if (*nb % 16 == 13)
// 		str[*i] = radix[3];
// 	else if (*nb % 16 == 14)
// 		str[*i] = radix[4];
// 	else if (*nb % 16 == 15)
// 		str[*i] = radix[5];
// 	else
// 		str[*i] = (*nb % 16) + '0';
// }

// char		*ft_itoa_16(unsigned int n, const char *radix)
// {
// 	int				i;
// 	unsigned int	nb;
// 	char			*str;

// 	i = 1;
// 	nb = n;
// 	while ((n / 16 ) != 0 && i++)
// 		n = (n / 16);
// 	if (!(str = (char *)malloc((i + 1))))
// 		return (NULL);
// 	str[i] = '\0';
// 	while (i--> 0)
// 	{
// 		check_hex(&nb, &i, str, radix);
// 		nb = nb / 16;
// 	}
// 	return (str);
// }

int main()
{
	printf("|%x|\n", -255);
	printf("|%s|\n", ft_itoa_16(-255, "abcdef"));
	return (0);
}

// 255 % 16 = 15 (F)
// 255 / 16
// 15 % 16 = 15 (F)
// 15 / 16 = 0
// 0 % 16 = (0)  

