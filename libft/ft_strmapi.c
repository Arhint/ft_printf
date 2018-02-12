/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssavchen <ssavchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 13:30:49 by ssavchen          #+#    #+#             */
/*   Updated: 2017/11/08 16:49:22 by ssavchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	unsigned int	l;
	char			*res;

	if (s && f)
	{
		i = 0;
		l = ft_strlen(s);
		res = (char *)malloc(sizeof(char) * (l + 1));
		if (res == NULL)
			return (NULL);
		while (i < l)
		{
			res[i] = f(i, s[i]);
			i++;
		}
		res[i] = '\0';
		return (res);
	}
	return (0);
}
