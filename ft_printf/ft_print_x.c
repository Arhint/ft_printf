/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_x.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssavchen <ssavchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 15:02:08 by ssavchen          #+#    #+#             */
/*   Updated: 2018/02/12 16:48:34 by ssavchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_hashx(t_flg *lol, char *s, int c)
{
	if (lol->hash && ft_atoll(s) && c == 120)
	{
		ft_putchar('0');
		ft_putchar('x');
		lol->rin += 2;
		lol->hash = 0;
	}
	if (lol->hash && ft_atoll(s) && c == 88)
	{
		ft_putchar('0');
		ft_putchar('X');
		lol->rin += 2;
		lol->hash = 0;
	}
	ft_print_hasho(lol, s, c);
}

void	ft_minuswidth(t_flg *lol, int c)
{
	lol->width -= 2;
	if (c == 111 || c == 79)
		lol->width++;
}

int		ft_print_xx(t_flg *lol, char *s, int len, int c)
{
	len = ft_print_zerodi(lol, s, len);
	if (lol->width && lol->hash)
		ft_minuswidth(lol, c);
	if (lol->width > 0)
		lol->width -= len;
	if (!lol->minus)
		ft_notminusx(lol, s, len, c);
	else
	{
		ft_print_hashx(lol, s, c);
		if (lol->prec > lol->width)
		{
			ft_print_prec(lol, len);
			ft_print_res(lol, s, len);
		}
		else
		{
			if (lol->prec > 0)
				ft_print_prec(lol, len);
			ft_print_res(lol, s, len);
			ft_print_widthx(lol, s, c);
		}
	}
	ft_strdel(&s);
	return (lol->rin);
}

int		ft_print_x(va_list ap, t_flg *lol, int c)
{
	void	*n;
	char	*res;
	int		len;

	n = va_arg(ap, void *);
	if (!lol->l && !lol->ll && !lol->h && !lol->hh && !lol->j && !lol->z)
		res = ft_itoa_baseull((unsigned int)n, 16);
	if (lol->l)
		res = ft_itoa_baseull((unsigned long int)n, 16);
	if (lol->ll)
		res = ft_itoa_baseull((unsigned long long int)n, 16);
	if (lol->h)
		res = ft_itoa_baseull((unsigned short int)n, 16);
	if (lol->hh)
		res = ft_itoa_baseull((unsigned char)n, 16);
	if (lol->j)
		res = ft_itoa_baseull((uintmax_t)n, 16);
	if (lol->z)
		res = ft_itoa_baseull((size_t)n, 16);
	len = (int)ft_strlen(res);
	if (c == 88)
		ft_bigx(res);
	lol->space = 0;
	lol->plusik = 0;
	return (ft_print_xx(lol, res, len, c));
}

char	*ft_bigx(char *s)
{
	int i;

	i = 0;
	while (s[i])
	{
		s[i] = ft_toupper(s[i]);
		i++;
	}
	return (s);
}
