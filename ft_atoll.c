#include "includes/ft_printf.h"

intmax_t	ft_atoll(const char *str)
{
	int			i;
	int			neg;
	intmax_t	res;
	
	res = 0;
	i = 0;
	neg = 1;
	while (ft_blanks(str[i]))
		i++;
	if (str[i] == '-')
		neg = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + str[i] - 48;
		i++;
	}
	return (res * neg);
}
