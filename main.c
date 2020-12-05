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

int main()
{
	printf("string: %.s", "hello");
	return (0);
}