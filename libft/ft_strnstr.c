/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssavchen <ssavchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 13:30:49 by ssavchen          #+#    #+#             */
/*   Updated: 2017/11/08 17:30:27 by ssavchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t l)
{
	size_t	i;
	size_t	j;
	char	*res;

	i = 0;
	if (little[0] == '\0')
		return ((char*)big);
	while (big[i] != '\0' && i < l)
	{
		if (big[i] == little[0])
		{
			res = 0;
			j = 0;
			res = &((char*)big)[i];
			while (big[i + j] == little[j] && i + j < l)
			{
				if (little[j + 1] == '\0')
					return (res);
				j++;
			}
		}
		i++;
	}
	return (0);
}
