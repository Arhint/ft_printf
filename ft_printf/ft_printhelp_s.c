/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhelp_s.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssavchen <ssavchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 15:12:48 by ssavchen          #+#    #+#             */
/*   Updated: 2018/02/12 16:24:31 by ssavchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_lenwchar(wchar_t s)
{
	int		k;

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

int		ft_lenswchar(wchar_t *s)
{
	int		i;
	int		len;

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
	int		i;

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
	int		i;
	int		j;

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

int		ft_print_bs(t_flg *lol, wchar_t *s)
{
	int		len;
	int		len2;
	int		i;

	i = 0;
	len = (int)ft_lenswchar(s);
	if (len > lol->prec && lol->prec >= 0)
	{
		len = lol->prec;
		len = ft_helpprec(lol, s, len);
	}
	len2 = len;
	if (lol->minus)
		len = ft_minusbigs(lol, s, len);
	if (lol->width && lol->width > len2)
		while (lol->width-- != len2)
			ft_zerospace(lol);
	while (len > 0)
	{
		if (len - ft_lenwchar(s[i]) >= 0)
			ft_helpcbig4(lol, s[i]);
		len -= ft_lenwchar(s[i]);
		i++;
	}
	return (lol->rin);
}
