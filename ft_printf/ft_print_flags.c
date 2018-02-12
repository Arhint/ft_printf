/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_flags.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssavchen <ssavchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 13:14:00 by ssavchen          #+#    #+#             */
/*   Updated: 2018/02/12 15:54:11 by ssavchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_plus_space(t_flg *lol, char *s)
{
	if (lol->sign)
	{
		ft_putchar('-');
		lol->rin++;
		lol->sign = 0;
	}
	if (lol->space && !lol->plusik && ft_atoll(s) >= 0)
	{
		ft_putchar(' ');
		lol->rin++;
		lol->space = 0;
	}
	if (ft_atoll(s) >= 0 && lol->plusik)
	{
		ft_putchar('+');
		lol->rin++;
		lol->plusik = 0;
		lol->space = 0;
	}
}

int		ft_print_zerodi(t_flg *lol, char *s, int len)
{
	if (ft_atoll(s) == 0 && lol->prec == 0)
	{
		s[0] = '\0';
		len = 0;
	}
	return (len);
}

void	ft_notminus(t_flg *lol, char *s, int len)
{
	if (lol->width > 0 && lol->prec > len)
		lol->width -= (lol->prec - len);
	ft_print_width(lol, s);
	if (lol->prec > lol->width)
	{
		ft_plus_space(lol, s);
		ft_print_prec(lol, len);
	}
	else
	{
		if (lol->width > 0 && lol->prec > len)
			lol->width -= (lol->prec - len);
		ft_print_width(lol, s);
		ft_print_prec(lol, len);
	}
	ft_print_res(lol, s, len);
}

void	ft_zerospace(t_flg *lol)
{
	if (lol->zero)
		ft_putchar('0');
	else
		ft_putchar(' ');
	lol->rin++;
}
