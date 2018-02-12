/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssavchen <ssavchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 13:30:49 by ssavchen          #+#    #+#             */
/*   Updated: 2017/11/08 17:19:56 by ssavchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		ft_ret(char const *s)
{
	int start;
	int end;
	int len;

	start = 0;
	end = ft_strlen(s);
	while ((s[start] == ' ' || s[start] == '\n' || s[start] == '\t')
		&& s[start] != '\0')
		start++;
	if (s[start] != '\0')
		while (s[end - 1] == ' ' || s[end - 1] == '\n' || s[end - 1] == '\t')
			end--;
	len = end - 1 - start + 1;
	return (len);
}

char			*ft_strtrim(char const *s)
{
	int		start;
	int		i;
	int		len;
	char	*res;

	if (s)
	{
		i = 0;
		start = 0;
		while ((s[start] == ' ' || s[start] == '\n' || s[start] == '\t')
			&& s[start] != '\0')
			start++;
		len = ft_ret(s);
		res = (char *)malloc(sizeof(char) * (len + 1));
		if (res == NULL)
			return (NULL);
		while (len > 0)
		{
			res[i++] = s[start++];
			len--;
		}
		res[i] = '\0';
		return (res);
	}
	return (0);
}
