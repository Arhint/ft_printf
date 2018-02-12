/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssavchen <ssavchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 13:30:49 by ssavchen          #+#    #+#             */
/*   Updated: 2017/11/09 12:14:09 by ssavchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	char	*word(char const *s, char c)
{
	int		i;
	char	*res;

	i = 0;
	while (s[i] != c && s[i] != '\0')
		i++;
	res = (char *)malloc(sizeof(char) * (i + 1));
	if (res == NULL)
		return (NULL);
	i = 0;
	while (s[i] != c && s[i])
	{
		res[i] = s[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**res;
	int		i;
	int		num_words;
	int		j;

	if (s)
	{
		i = 0;
		j = 0;
		num_words = ft_count_words(s, c);
		if ((res = (char **)malloc(sizeof(char *) * num_words + 1)) == NULL)
			return (NULL);
		while (s[i] != '\0')
		{
			while (s[i] == c && s[i] != '\0')
				i++;
			if (s[i] != c && s[i] != '\0')
				res[j++] = word(&s[i], c);
			while (s[i] != c && s[i])
				i++;
		}
		res[j] = 0;
		return (res);
	}
	return (0);
}
