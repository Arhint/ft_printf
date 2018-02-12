/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssavchen <ssavchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 13:30:49 by ssavchen          #+#    #+#             */
/*   Updated: 2017/11/08 15:52:07 by ssavchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	size_t	i;
	size_t	j;
	char	*res;

	i = 0;
	if (little[0] == '\0')
		return ((char*)big);
	while (big[i] != '\0')
	{
		if (big[i] == little[0])
		{
			j = 0;
			res = 0;
			res = &((char*)big)[i];
			while (big[i + j] == little[j])
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
