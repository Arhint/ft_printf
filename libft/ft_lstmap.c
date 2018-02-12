/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssavchen <ssavchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 13:30:49 by ssavchen          #+#    #+#             */
/*   Updated: 2017/11/08 16:04:14 by ssavchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*begin;
	t_list	*tmp;
	t_list	*res;

	if (!lst || !f)
		return (NULL);
	tmp = f(lst);
	res = ft_lstnew(tmp->content, tmp->content_size);
	if (!res)
		return (NULL);
	lst = lst->next;
	begin = res;
	while (lst)
	{
		tmp = f(lst);
		res->next = ft_lstnew(tmp->content, tmp->content_size);
		if (!res->next)
			return (NULL);
		res = res->next;
		lst = lst->next;
	}
	return (begin);
}
