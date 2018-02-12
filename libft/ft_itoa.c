/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssavchen <ssavchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 13:30:49 by ssavchen          #+#    #+#             */
/*   Updated: 2017/11/09 12:46:23 by ssavchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	char	*ft(char *res, int l, int n)
{
	res[l--] = '\0';
	if (n == 0)
		res[0] = 0 + 48;
	if (n == -2147483648)
	{
		res[0] = '-';
		res[1] = '2';
		n = 147483648;
	}
	if (n < 0)
	{
		res[0] = '-';
		n = -n;
	}
	while (n != 0)
	{
		res[l--] = n % 10 + 48;
		n /= 10;
	}
	return (res);
}

char			*ft_itoa(int n)
{
	int		l;
	char	*res;

	l = ft_len_int(n);
	res = (char *)malloc(sizeof(char) * l + 1);
	if (res == NULL)
		return (NULL);
	return (ft(res, l, n));
}
