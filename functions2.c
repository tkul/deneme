#include "ft_printf.h"

static int	ft_to_hex_pf(size_t n, int i, char *set)
{
	if (n >= 16)
	{
		i = ft_to_hex_pf(n / 16, i, set);
		i = ft_to_hex_pf(n % 16, i, set);
	}
	else
	{
		n = set[n];
		write(1, &n, 1);
		i++;
	}
	return (i);
}

int	ft_putadress_print(void *p, int i)
{
	size_t	n;

	n = (size_t)p;
	write(1, "0x", 2);
	i = ft_to_hex_pf(n, i, "0123456789abcdef");
	return (i);
}
