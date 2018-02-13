/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssavchen <ssavchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 15:06:06 by ssavchen          #+#    #+#             */
/*   Updated: 2018/02/13 12:52:24 by ssavchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_flg	*ft_reset_flg(t_flg *lol)
{
	lol->minus = 0;
	lol->plusik = 0;
	lol->space = 0;
	lol->zero = 0;
	lol->hash = 0;
	lol->width = 0;
	lol->prec = -1;
	lol->h = 0;
	lol->hh = 0;
	lol->l = 0;
	lol->ll = 0;
	lol->j = 0;
	lol->z = 0;
	lol->sign = 0;
	return (lol);
}

int		ft_cook(char *s, va_list ap, int i, t_flg *lol)
{
	if (s[i] == 'd' || s[i] == 'i' || s[i] == 'D')
		ft_print_di(ap, lol, s[i]);
	if (s[i] == 's')
		ft_print_s(ap, lol);
	if (s[i] == 'c')
		ft_print_c(ap, lol);
	if (s[i] == 'C')
		ft_print_cbig(ap, lol);
	if (s[i] == 'x' || s[i] == 'X')
		ft_print_x(ap, lol, s[i]);
	if (s[i] == 'o' || s[i] == 'O')
		ft_print_o(ap, lol, s[i]);
	if (s[i] == 'p')
		ft_print_p(ap, lol);
	if (s[i] == 'u' || s[i] == 'U')
		ft_print_u(ap, lol, s[i]);
	if (s[i] == 'S')
		ft_print_bigs(ap, lol);
	if (s[i] == 'b')
		ft_print_b(ap, lol);
	return (i);
}

int		ft_define(char *s, va_list ap, t_flg *lol)
{
	int		i;

	i = 0;
	while (s[i])
	{
		while (s[i] != '%' && s[i])
		{
			ft_putchar(s[i++]);
			lol->rin++;
		}
		if (s[i] == '%')
			i = ft_fill_flg(lol, s, i);
		if ((ft_strchr("sSpdDioOuUxXcCb", s[i])))
			i = ft_cook(s, ap, i, lol);
		else
			ft_print_cc(lol, s[i]);
		if (s[i])
			i++;
		lol = ft_reset_flg(lol);
	}
	return (lol->rin);
}

int		ft_printf(char *format, ...)
{
	va_list	ap;
	int		n;
	t_flg	*lol;

	lol = ft_create_flg();
	va_start(ap, format);
	n = ft_define(format, ap, lol);
	va_end(ap);
	free(lol);
	return (n);
}
