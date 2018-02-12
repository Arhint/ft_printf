/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssavchen <ssavchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 15:24:41 by ssavchen          #+#    #+#             */
/*   Updated: 2017/12/08 12:49:57 by ssavchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_strchr(const char *s, int c)
{
	size_t	i;
	char	*res;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (unsigned char)c)
		{
			res = &((char*)s)[i];
			return (res);
		}
		i++;
	}
	if (s[i] == (unsigned char)c)
	{
		res = &((char*)s)[i];
		return (res);
	}
	return (0);
}
