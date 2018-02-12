/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_c.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arh <arh@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 14:33:57 by ssavchen          #+#    #+#             */
/*   Updated: 2018/02/13 00:09:09 by arh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_print_cc(t_flg *lol, char c)
{
	char	*res;

	res = (char *)malloc(sizeof(char) + 1);
	res[0] = c;
	res[1] = '\0';
	lol->prec = -1;
	lol->space = 0;
	lol->width--;
	if (!lol->minus)
	{
		ft_print_width(lol, res);
		ft_putchar(c);
		lol->rin++;
	}
	else
	{
		ft_putchar(c);
		lol->rin++;
		ft_print_width(lol, res);
	}
	ft_strdel(&res);
	return (lol->rin);
}

int		ft_print_c(va_list ap, t_flg *lol)
{
	char	*res;
	int		c;

	if (lol->l)
		return (ft_print_cbig(ap, lol));
	res = (char *)malloc(2);
	c = va_arg(ap, int);
	res[0] = c;
	res[1] = '\0';
	lol->space = 0;
	lol->plusik = 0;
	lol->prec = -1;
	lol->width--;
	if (!lol->minus)
	{
		ft_print_width(lol, res);
		ft_putchar(c);
	}
	else
	{
		ft_putchar(c);
		ft_print_width(lol, res);
	}
	ft_strdel(&res);
	return (lol->rin++);
}

int		ft_helpcbig5(t_flg *lol, int c)
{
	ft_putchar((c >> 21) + 240);
	ft_putchar(((c >> 12) & 63) + 128);
	ft_putchar(((c >> 6) & 63) + 128);
	ft_putchar((c & 63) + 128);
	lol->rin += 4;
	return (lol->rin);
}

int		ft_helpcbig4(t_flg *lol, int c)
{
	if (c <= 127)
	{
		ft_putchar(c);
		lol->rin++;
	}
	if (c > 127 && c <= 2047)
	{
		ft_putchar((c >> 6) + 192);
		ft_putchar((c & 63) + 128);
		lol->rin += 2;
	}
	if (c > 2047 && c <= 65535)
	{
		ft_putchar((c >> 12) + 224);
		ft_putchar(((c >> 6) & 63) + 128);
		ft_putchar((c & 63) + 128);
		lol->rin += 3;
	}
	if (c > 65535 && c <= 1114111)
		ft_helpcbig5(lol, c);
	return (lol->rin);
}

int		ft_print_cbig(va_list ap, t_flg *lol)
{
	int		c;

	if (MB_CUR_MAX == 1)
		return (ft_print_c(ap, lol));
	c = va_arg(ap, int);
	if (c <= 127)
		lol->rin = ft_helpcbig4(lol, c);
	if (c > 127 && c <= 2047)
		lol->rin = ft_helpcbig4(lol, c);
	if (c > 2047 && c <= 65535)
		lol->rin = ft_helpcbig4(lol, c);
	if (c > 65535 && c <= 1114111)
		lol->rin = ft_helpcbig4(lol, c);
	return (lol->rin);
}
