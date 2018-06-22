/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarcink <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/22 09:06:14 by mmarcink          #+#    #+#             */
/*   Updated: 2018/06/22 09:06:14 by mmarcink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t	byte;
	char	*b_ptr;

	byte = -1;
	b_ptr = b;
	while (++byte < len)
		*(b_ptr + byte) = c;
	return (b);
}
