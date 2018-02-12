/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssavchen <ssavchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 17:29:00 by ssavchen          #+#    #+#             */
/*   Updated: 2017/11/09 17:29:32 by ssavchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_sqrt(int nb)
{
	int left;
	int right;
	int mid;

	right = 46340;
	left = 0;
	while (1)
	{
		mid = (left + right) / 2;
		if (mid * mid == nb)
			return (mid);
		if (mid * mid < nb)
			left = mid + 1;
		if (mid * mid > nb)
			right = mid - 1;
		if (left > right)
			return (0);
	}
}
