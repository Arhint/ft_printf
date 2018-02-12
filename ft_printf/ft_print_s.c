/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssavchen <ssavchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 14:56:42 by ssavchen          #+#    #+#             */
/*   Updated: 2018/02/12 17:14:06 by ssavchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_print_bigs(va_list ap, t_flg *lol)
{
	int			i;
	wchar_t		*s;
	int			len;

	s = va_arg(ap, wchar_t *);
	i = 0;
	if (s == NULL)
		return (ft_zeros(lol));
	lol->rin = ft_print_bs(lol, s);
	return (lol->rin);
}

int		ft_print_s(va_list ap, t_flg *lol)
{
	char	*res;
	int		k;

	if (lol->l)
		return (ft_print_bigs(ap, lol));
	res = va_arg(ap, char *);
	return (ft_print_es(lol, res));
}

int		ft_zeros(t_flg *lol)
{
	char	*res;

	res = ft_strdup("(null)");
	lol->rin = ft_print_es(lol, res);
	ft_strdel(&res);
	return (lol->rin);
}

int		ft_minuss(t_flg *lol, char *s, int len)
{
	while (len)
	{
		lol->zero = 0;
		ft_putchar(*(s)++);
		len--;
	}
	return (len);
}

int		ft_print_es(t_flg *lol, char *s)
{
	int		len;
	int		len2;

	if (s == NULL)
		return (ft_zeros(lol));
	len = (int)ft_strlen(s);
	if (len > lol->prec && lol->prec >= 0)
		len = lol->prec;
	len2 = len;
	lol->rin += len;
	if (lol->minus)
		len = ft_minuss(lol, s, len);
	if (lol->width && lol->width > len2)
	{
		while (lol->width-- != len2)
			ft_zerospace(lol);
	}
	while (len--)
		ft_putchar(*(s)++);
	return (lol->rin);
}
