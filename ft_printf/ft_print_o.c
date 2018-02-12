/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_o.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arh <arh@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 14:53:05 by ssavchen          #+#    #+#             */
/*   Updated: 2018/02/13 00:07:57 by arh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_hasho(t_flg *lol, char *s, int c)
{
	if (lol->hash && ft_atoll(s) && (c == 111 || c == 79))
	{
		ft_putchar('0');
		lol->rin++;
		lol->hash = 0;
		lol->prec--;
	}
	if (lol->hash && !ft_atoll(s) && !lol->prec && (c == 111 || c == 79))
	{
		ft_putchar('0');
		lol->rin++;
		lol->hash = 0;
		lol->prec--;
	}
}

int		ft_print_o(va_list ap, t_flg *lol, int c)
{
	void	*n;
	char	*res;
	int		len;

	n = va_arg(ap, void *);
	if (!lol->l && !lol->ll && !lol->h && !lol->hh && !lol->j && !lol->z &&
			c != 'O')
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

int		ft_rei(t_flg *lol, int i)
{
	if (lol->j || lol->z || lol->h || lol->l)
		i++;
	if (lol->hh || lol->ll)
		i += 2;
	return (i);
}
