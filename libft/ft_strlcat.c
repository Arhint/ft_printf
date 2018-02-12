/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssavchen <ssavchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 13:30:49 by ssavchen          #+#    #+#             */
/*   Updated: 2017/11/08 15:48:15 by ssavchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t i;
	size_t l;

	i = 0;
	l = ft_strlen(dst);
	while (src[i] != '\0' && l + i + 1 < size)
	{
		dst[l + i] = src[i];
		i++;
	}
	dst[l + i] = '\0';
	while (src[i])
		i++;
	if (l > size)
		return (i + size);
	return (i + l);
}
