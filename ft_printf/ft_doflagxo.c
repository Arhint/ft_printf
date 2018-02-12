/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_doflagxo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssavchen <ssavchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 16:37:00 by ssavchen          #+#    #+#             */
/*   Updated: 2018/02/12 14:28:23 by ssavchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_widthx(t_flg *lol, char *s, int c)
{
	if (lol->width > 0)
	{
		while (lol->width > 0)
		{
			if (!lol->zero || lol->minus || lol->prec > 0)
				ft_putchar(' ');
			else
			{
				ft_print_piks(lol, c);
				ft_print_hashx(lol, s, c);
				ft_putchar('0');
			}
			lol->width--;
			lol->rin++;
		}
	}
	ft_print_piks(lol, c);
	ft_print_hashx(lol, s, c);
}

void	ft_notminusx(t_flg *lol, char *s, int len, int c)
{
	if (lol->prec > lol->width + len)
	{
		ft_print_piks(lol, c);
		ft_print_hashx(lol, s, c);
		ft_print_prec(lol, len);
	}
	else
	{
		if (lol->width > 0 && lol->prec > len)
			lol->width -= (lol->prec - len);
		ft_print_widthx(lol, s, c);
		ft_print_prec(lol, len);
	}
	ft_print_res(lol, s, len);
}
