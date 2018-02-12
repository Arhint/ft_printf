/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssavchen <ssavchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 16:52:00 by ssavchen          #+#    #+#             */
/*   Updated: 2018/02/12 16:54:43 by ssavchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_piks(t_flg *lol, int c)
{
	if (c == 65 && lol->hash)
	{
		ft_putchar('0');
		ft_putchar('x');
		lol->rin += 2;
		lol->hash = 0;
	}
}

int		ft_print_pe(t_flg *lol, char *s, int len, int c)
{
	len = ft_print_zerodi(lol, s, len);
	if (lol->width > 0)
		lol->width -= len;
	if (!lol->minus)
		ft_notminusx(lol, s, len, c);
	else
	{
		ft_print_piks(lol, 65);
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

int		ft_print_p(va_list ap, t_flg *lol)
{
	char	*res;
	void	*n;
	int		len;

	n = (va_arg(ap, void *));
	res = ft_itoa_baseull((unsigned long long)n, 16);
	len = ft_strlen(res);
	lol->sign = 0;
	lol->hash = 1;
	lol->width -= 2;
	return (ft_print_pe(lol, res, len, 65));
}
