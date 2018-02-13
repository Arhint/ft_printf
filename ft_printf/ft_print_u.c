/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_u.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssavchen <ssavchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 16:19:00 by ssavchen          #+#    #+#             */
/*   Updated: 2018/02/13 12:54:02 by ssavchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_print_u(va_list ap, t_flg *lol, int c)
{
	void	*n;
	char	*res;
	int		len;

	n = va_arg(ap, void *);
	if (!lol->l && !lol->ll && !lol->h && !lol->hh && !lol->j && !lol->z &&
			c != 'U')
		res = ft_itoa_baseull((unsigned int)n, 10);
	if (lol->l || c == 'U')
		res = ft_itoa_baseull((unsigned long int)n, 10);
	if (lol->ll)
		res = ft_itoa_baseull((unsigned long long int)n, 10);
	if (lol->h && c != 'U')
		res = ft_itoa_baseull((unsigned short int)n, 10);
	if (lol->hh && c != 'U')
		res = ft_itoa_baseull((unsigned char)n, 10);
	if (lol->j)
		res = ft_itoa_baseull((uintmax_t)n, 10);
	if (lol->z)
		res = ft_itoa_baseull((size_t)n, 10);
	len = ft_strlen(res);
	lol->plusik = 0;
	lol->space = 0;
	return (ft_print_flagsdi(lol, res, len));
}

int		ft_print_b(va_list ap, t_flg *lol)
{
	void	*n;
	char	*res;
	int		len;

	n = va_arg(ap, void *);
	if (!lol->l && !lol->ll && !lol->h && !lol->hh && !lol->j && !lol->z)
		res = ft_itoa_baseull((unsigned int)n, 2);
	if (lol->l)
		res = ft_itoa_baseull((unsigned long int)n, 2);
	if (lol->ll)
		res = ft_itoa_baseull((unsigned long long int)n, 2);
	if (lol->h)
		res = ft_itoa_baseull((unsigned short int)n, 2);
	if (lol->hh)
		res = ft_itoa_baseull((unsigned char)n, 2);
	if (lol->j)
		res = ft_itoa_baseull((uintmax_t)n, 2);
	if (lol->z)
		res = ft_itoa_baseull((size_t)n, 2);
	len = (int)ft_strlen(res);
	lol->space = 0;
	lol->plusik = 0;
	return (ft_print_xx(lol, res, len, 111));
}
