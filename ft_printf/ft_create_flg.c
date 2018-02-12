/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_flg.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssavchen <ssavchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 14:20:09 by ssavchen          #+#    #+#             */
/*   Updated: 2018/02/12 17:55:29 by ssavchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_length(t_flg *lol, char *s, int i)
{
	if (s[i] == 'j')
		lol->j = 1;
	if (s[i] == 'z')
		lol->z = 1;
	if (s[i] == 'l' && s[i + 1] != 'l')
		lol->l = 1;
	if (s[i] == 'l' && s[i + 1] == 'l')
		lol->ll = 1;
	if (s[i] == 'h' && s[i + 1] != 'h')
		lol->h = 1;
	if (s[i] == 'h' && s[i + 1] == 'h')
		lol->hh = 1;
	return (ft_rei(lol, i));
}

int		ft_precision(t_flg *lol, char *s, int i)
{
	if (s[i] == '.')
	{
		lol->prec = 0;
		i++;
		while (ft_isdigit(s[i]))
		{
			lol->prec = lol->prec * 10 + s[i] - 48;
			i++;
		}
	}
	return (i);
}

int		ft_width(t_flg *lol, char *s, int i)
{
	while (ft_isdigit(s[i]))
	{
		lol->width = lol->width * 10 + s[i] - 48;
		i++;
	}
	return (i);
}

int		ft_fill_flg(t_flg *lol, char *s, int i)
{
	i++;
	while (s[i] != '\0' && (ft_strchr("-+ 0#", s[i])))
	{
		if (s[i] == '-')
			lol->minus = 1;
		if (s[i] == '+')
			lol->plusik = 1;
		if (s[i] == ' ')
			lol->space = 1;
		if (s[i] == '0')
			lol->zero = 1;
		if (s[i] == '#')
			lol->hash = 1;
		i++;
	}
	i = ft_width(lol, s, i);
	i = ft_precision(lol, s, i);
	i = ft_length(lol, s, i);
	return (i);
}

t_flg	*ft_create_flg(void)
{
	t_flg	*lol;

	if (!(lol = (t_flg *)malloc(sizeof(t_flg))))
		return (NULL);
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
	lol->rin = 0;
	lol->sign = 0;
	return (lol);
}
