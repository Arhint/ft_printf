/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssavchen <ssavchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 13:30:49 by ssavchen          #+#    #+#             */
/*   Updated: 2018/01/10 16:20:10 by ssavchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	l1;
	size_t	l2;
	size_t	j;
	char	*res;

	if (s1 && s2)
	{
		j = 0;
		i = 0;
		l1 = ft_strlen(s1);
		l2 = ft_strlen(s2);
		if ((res = (char *)malloc(sizeof(char) * (l1 + l2 + 1))) == NULL)
			return (NULL);
		while (s1[i])
		{
			res[i] = s1[i];
			i++;
		}
		while (s2[j])
			res[i++] = s2[j++];
		res[i] = '\0';
		return (res);
	}
	return (0);
}
