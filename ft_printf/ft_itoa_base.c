/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssavchen <ssavchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 14:33:25 by ssavchen          #+#    #+#             */
/*   Updated: 2018/02/12 16:53:31 by ssavchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_itoa_basell(intmax_t value, int base)
{
	long long int	n;
	int				i;
	char			*res;
	char			*hex;

	hex = "0123456789abcdef";
	n = value;
	i = 1;
	if (value < 0 && base == 10)
		i++;
	while (n /= base)
		i++;
	if ((res = (char*)malloc(sizeof(char) * i + 1)) == NULL)
		return (NULL);
	if (value < 0 && base == 10)
		res[0] = '-';
	res[i] = '\0';
	if (value == 0)
		res[0] = '0';
	while (value)
	{
		res[--i] = hex[value < 0 ? -(value % base) : (value % base)];
		value /= base;
	}
	return (res);
}

char	*ft_itoa_baseull(unsigned long long value, int base)
{
	size_t	n;
	int		i;
	char	*res;
	char	*hex;

	hex = "0123456789abcdef";
	n = value;
	i = 1;
	while (n /= base)
		i++;
	if ((res = (char*)malloc(sizeof(char) * i + 1)) == NULL)
		return (NULL);
	res[i] = '\0';
	if (value == 0)
		res[0] = '0';
	while (value)
	{
		res[--i] = hex[value % base];
		value /= base;
	}
	return (res);
}
