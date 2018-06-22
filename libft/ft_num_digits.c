/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_num_digits.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarcink <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 16:20:53 by mmarcink          #+#    #+#             */
/*   Updated: 2018/03/12 16:20:53 by mmarcink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_num_digits(long long z)
{
	int count;

	count = 0;
	if (z < 0)
		count++;
	if (z == 0)
		return (1);
	while (z != 0)
	{
		z /= 10;
		count++;
	}
	return (count);
}
