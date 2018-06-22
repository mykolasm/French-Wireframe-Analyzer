/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarcink <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/22 09:06:13 by mmarcink          #+#    #+#             */
/*   Updated: 2018/06/22 09:06:13 by mmarcink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*src_cpy;
	char	*dst_cpy;
	size_t	i;

	src_cpy = (char *)src;
	dst_cpy = (char *)dst;
	i = -1;
	while (++i < n)
		*(dst_cpy + i) = *(src_cpy + i);
	return (dst);
}
