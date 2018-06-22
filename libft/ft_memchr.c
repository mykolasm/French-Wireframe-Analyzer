/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarcink <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/22 09:06:13 by mmarcink          #+#    #+#             */
/*   Updated: 2018/06/22 09:06:13 by mmarcink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char *s_cpy;
	unsigned char cb;

	cb = c;
	s_cpy = (unsigned char *)s;
	while (n > 0)
	{
		if (*s_cpy == cb)
			return (s_cpy);
		s_cpy++;
		n--;
	}
	return (NULL);
}
