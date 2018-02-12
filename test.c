/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssavchen <ssavchen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/08 18:22:00 by ssavchen          #+#    #+#             */
/*   Updated: 2018/02/08 18:22:00 by ssavchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_print_bs(t_flg *lol, char *s)
{
	int 	len;
	int 	len2;
	
	if (s == NULL)
		return (ft_zeros(lol));
	len = (int)ft_lenswchar(s);
	if (len > lol->prec && lol->prec >= 0)
		len = lol->prec;
	len2 = len;
	lol->rin += len;
	if (lol->minus)
		len = ft_minuss(lol, s, len);
	if (lol->width && lol->width > len2)
	{
		while (lol->width-- != len2)
		{
			if (lol->zero)
				ft_putchar('0');
			else
				ft_putchar(' ');
			lol->rin++;
		}
	}
	while (len--)
		ft_putchar(*(s)++);
	return (lol->rin);
}
