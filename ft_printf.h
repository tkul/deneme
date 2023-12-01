#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

int	ft_printf(const char *format, ...);
int	ft_putchar_print(char c, int i);
int	ft_putstr_print(char *s, int i);
int	ft_putnbr_print(long n, int i);
int	ft_putnbr_unsigned(unsigned int n, int i);
int	ft_putadress_print(void *p, int i);
int	ft_puthex_print(unsigned int x, int i, char format);
int	ft_hex_len(unsigned	int num);
void	ft_put_hex(unsigned int num, const char format);

#endif