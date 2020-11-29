#include <stdio.h>
#include <math.h>
#include "ft_printf.h"

int main()
{
	// char *s = "Hello!";
	// printf( "%.5s = %0*.*f", "value trash", 10, 5, M_PI );
	printf("%0 *.18d",__INT_MAX__ + 10, 189);
	return (0);
}