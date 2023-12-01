int	ft_hex_len(unsigned	int num)
{
	int	i;

	i = 0;
	while (num > 0)
	{
		num = num / 16;
		i++;
	}
	return (i);
}

void	ft_put_hex(unsigned int num, const char format)
{
	char	*hex;
	int		len;

	if (format == 'x')
		hex = "0123456789abcdef";
	else
		hex = "0123456789ABCDEF";
	len = ft_hex_len(num);
	while (len > 0)
	{
		write(1, &hex[num / ft_pow(16, len - 1)], 1);
		num = num % ft_pow(16, len - 1);
		len--;
	}
}

int	ft_puthex_print(unsigned int x, int i, char format)
{
	if (x >= 16)
	{
		i = ft_puthex_print(x / 16, i, format);
		i = ft_puthex_print(x % 16, i, format);
	}
	else
	{
		ft_put_hex(x, format);
		i++;
	}
	return (i);
}
