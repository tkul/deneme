#include "ft_printf.h"

int	ft_putchar_print(char c, int i)
{
	write(1, &c, 1);
	return (i + 1);
}

int	ft_putstr_print(char *s, int i)
{
	int	j;

	j = 0;
	while (s[j] != '\0')
	{
		write(1, &s[j], 1);
		j++;
		i++;
	}
	return (i);
}

int	ft_putnbr_print(long n, int i)
{
	if (n < 0)
	{
		write(1, "-", 1);
		n = n * -1;
		i++;
	}
	if (n >= 10)
	{
		i = ft_putnbr_print(n / 10, i);
		i = ft_putnbr_print(n % 10, i);
	}
	else
	{
		n = n + '0';
		write(1, &n, 1);
		i++;
	}
	return (i);
}

int	ft_putnbr_unsigned(unsigned int n, int i)
{
	if (n >= 10)
	{
		i = ft_putnbr_unsigned(n / 10, i);
		i = ft_putnbr_unsigned(n % 10, i);
	}
	else
	{
		n = n + '0';
		write(1, &n, 1);
		i++;
	}
	return (i);
}