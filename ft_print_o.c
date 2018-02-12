#include "includes/ft_printf.h"

int		ft_print_o(va_list ap, t_flg *lol, int c)
{
	void	*n;
	char	*res;
	int		len;

	n = va_arg(ap, void *);
	if (!lol->l && !lol->ll && !lol->h && !lol->hh && !lol->j && !lol->z)
		res = ft_itoa_baseull((unsigned int)n, 8);
	if (lol->l || c == 'O')
		res = ft_itoa_baseull((unsigned long int)n, 8);
	if (lol->ll)
		res = ft_itoa_baseull((unsigned long long int)n, 8);
	if (lol->h && c != 'O')
		res = ft_itoa_baseull((unsigned short int)n, 8);
	if (lol->hh && c != 'O')
		res = ft_itoa_baseull((unsigned char)n, 8);
	if (lol->j)
		res = ft_itoa_baseull((uintmax_t)n, 8);
	if (lol->z)
		res = ft_itoa_baseull((size_t)n, 8);
	len = (int)ft_strlen(res);
	lol->space = 0;
	lol->plusik = 0;
	return (ft_print_xx(lol, res, len, c));
}

