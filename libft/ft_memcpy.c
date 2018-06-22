/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarcink <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/01 16:37:27 by mmarcink          #+#    #+#             */
/*   Updated: 2018/03/01 16:37:27 by mmarcink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memcpy(void *restrict dst, const void *restrict src, size_t n)
{
	size_t	i;
	char	*dest;
	char	*sourc;

	i = 0;
	dest = (char *)dst;
	sourc = (char *)src;
	while (i < n)
	{
		dest[i] = sourc[i];
		i++;
	}
	return (dst);
}
