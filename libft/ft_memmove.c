/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarcink <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/01 16:59:51 by mmarcink          #+#    #+#             */
/*   Updated: 2018/03/01 16:59:51 by mmarcink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** similar to memcpy() as it also copies data from a source to destination.
** memcpy() leads to problems when source and destination addresses overlap as
** memcpy() simply copies data one by one from one location to another.
*/

#include "libft.h"

void		*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*d;
	unsigned char	*s;
	size_t			i;

	d = (unsigned char *)dst;
	s = (unsigned char *)src;
	i = 0;
	if (src > dst)
	{
		while (i < len)
		{
			d[i] = s[i];
			i++;
		}
	}
	else
		while (0 < len)
		{
			len--;
			d[len] = s[len];
		}
	return (dst);
}
