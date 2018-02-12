#include "includes/ft_printf.h"

int		ft_print_res(t_flg *lol, char *s, int len)
{
	int i;
	
	i = 0;
	if (s[0] == '-')
		i = 1;
	while (s[i])
	{
		ft_putchar(s[i++]);
		lol->rin++;
		len--;
	}
	return (len);
}

void	ft_print_width(t_flg *lol, char *s)
{
	if (lol->width > 0)
	{
		while (lol->width > 0)
		{
			if (!lol->zero || lol->minus || lol->prec > 0)
				ft_putchar(' ');
			else
			{
				ft_plus_space(lol, s);
				ft_putchar('0');
			}
			lol->width--;
			lol->rin++;
		}
	}
	ft_plus_space(lol, s);
}

void	ft_print_prec(t_flg *lol, int len)
{
	if (lol->prec > len)
		while (lol->prec - len > 0)
		{
			ft_putchar('0');
			lol->prec--;
			lol->width--;
			lol->rin++;
		}
	lol->prec = -1;
}

int		ft_print_flagsdi(t_flg *lol, char *s, int len)
{
	len = ft_print_zerodi(lol, s, len);
	if (lol->width && (lol->plusik || lol->sign || lol->space))
		lol->width--;
	if (lol->width > 0)
		lol->width -= len;
	if (!lol->minus)
		ft_notminus(lol, s, len);
	else
	{
		ft_plus_space(lol, s);
		if (lol->prec > lol->width)
			ft_print_prec(lol, len);
		else
		{
			if (lol->prec > 0)
				ft_print_prec(lol, len);
			ft_print_res(lol, s, len);
			ft_print_width(lol, s);
		}
	}
	return (lol->rin);
}

int		ft_print_di(va_list ap, t_flg *lol, int c)
{
	void	*di;
	char 	*res;
	int 	len;

	di = va_arg(ap, void *);
	if (!lol->l && !lol->ll && !lol->h && !lol->hh && !lol->j && !lol->z)
		res = ft_itoa_basell((int)di, 10);
	if (lol->l || c == 'D')
		res = ft_itoa_basell((long int)di, 10);
	if (lol->ll)
		res = ft_itoa_basell((long long int)di, 10);
	if (lol->h && c != 'D')
		res = ft_itoa_basell((short int)di, 10);
	if (lol->hh && c != 'D')
		res = ft_itoa_basell((char)di, 10);
	if (lol->j)
		res = ft_itoa_basell((intmax_t)di, 10);
	if (lol->z)
		res = ft_itoa_basell((size_t)di, 10);
	ft_atoll(res) < 0 ? (len = ft_strlen(res) - 1) : (len = ft_strlen(res));
	if (ft_atoll(res) < 0)
		lol->sign = 1;
	return (ft_print_flagsdi(lol, res, len));
}


