/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarcink <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/01 15:15:25 by mmarcink          #+#    #+#             */
/*   Updated: 2018/03/01 15:15:25 by mmarcink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** think of the counters as a countdown timer. just replace part of a string
** with some character then return the string...  like overwriting the string
*/

#include "libft.h"

void		*ft_memset(void *b, int c, size_t len)
{
	char *start;

	start = (char *)b;
	while (0 < len)
	{
		*start = c;
		start++;
		len--;
	}
	return (b);
}
