/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_flags.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssavchen <ssavchen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 13:14:00 by ssavchen          #+#    #+#             */
/*   Updated: 2018/01/29 13:14:00 by ssavchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

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

int 	ft_lenwchar(wchar_t s)
{
	int 	k;

	if (s <= 127)
		k = 1;
	if (s > 127 && s <= 2047)
		k = 2;
	if (s > 2047 && s <= 65535)
		k = 3;
	if (s > 65535 && s <= 1114111)
		k = 4;
	return (k);
}

int 	ft_lenswchar(wchar_t *s)
{
	int 	i;
	int 	len;
	
	len = 0;
	i = 0;
	while (s[i])
	{
		len += ft_lenwchar(s[i]);
		i++;
	}
	return (len);
}

int		ft_minusbigs(t_flg *lol, wchar_t *s, int len)
{
	int 	i;
	
	i = 0;
	while (len > 0)
	{
		lol->zero = 0;
		if (len - ft_lenwchar(s[i]) >= 0)
			ft_helpcbig4(lol, s[i]);
		len -= ft_lenwchar(s[i]);
		i++;
	}
	return (len);
}

int		ft_helpprec(t_flg *lol, wchar_t *s, int len)
{
	int i;
	int j;
	j = 0;
	i = 0;
	while (len > 0)
	{
		if (len - ft_lenwchar(s[j]) >= 0)
			i += ft_lenwchar(s[j]);
		len -= ft_lenwchar(s[j]);
		j++;
	}
	return (i);
}
