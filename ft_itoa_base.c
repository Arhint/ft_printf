#include "includes/ft_printf.h"

char	*ft_itoa_basell(intmax_t value, int base)
{
	long long int	n;
	int				i;
	char			*res;
	char			*hex;

	hex = "0123456789abcdef";
	n = value;
	i = 1;
	if (value < 0 && base == 10)
		i++;
	while (n /= base)
		i++;
	res = (char*)malloc(sizeof(char) * i + 1);
	if (value < 0 && base == 10)
		res[0] = '-';
	res[i] = '\0';
	if (value == 0)
		res[0] = '0';
	while (value)
	{
		res[--i] = hex[value < 0 ? -(value % base) : (value % base)];
		value /= base;
	}
	return (res);
}

char	*ft_itoa_baseull(unsigned long long value, int base)
{
	size_t	n;
	int		i;
	char	*res;
	char	*hex;

	hex = "0123456789abcdef";
	n = value;
	i = 1;
	while (n /= base)
		i++;
	res = (char*)malloc(sizeof(char) * i + 1);
	res[i] = '\0';
	if (value == 0)
		res[0] = '0';
	while (value)
	{
		res[--i] = hex[value % base];
		value /= base;
	}
	return (res);
}

