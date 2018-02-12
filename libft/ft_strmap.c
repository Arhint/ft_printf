/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssavchen <ssavchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 13:30:49 by ssavchen          #+#    #+#             */
/*   Updated: 2017/11/08 15:49:04 by ssavchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	size_t	i;
	size_t	l;
	char	*res;

	if (s && f)
	{
		i = 0;
		l = ft_strlen(s);
		res = (char *)malloc(sizeof(char) * l + 1);
		if (res == NULL)
			return (NULL);
		while (i < l)
		{
			res[i] = f(s[i]);
			i++;
		}
		res[i] = '\0';
		return (res);
	}
	return (0);
}
