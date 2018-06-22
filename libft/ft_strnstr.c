/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarcink <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 15:45:31 by mmarcink          #+#    #+#             */
/*   Updated: 2018/02/28 15:45:31 by mmarcink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** line31 (j - i) works because the j jumps ahead of i and runs till the limit
** so 0-0 is index 0, 1-0 index 1... etc. till limit. ONLY need 2 return first
** char of needle array
*/

#include "libft.h"
#include <xlocale.h>

char		*ft_strnstr(const char *h, const char *n, size_t len)
{
	int i;
	int j;

	i = 0;
	if (n[0] == '\0')
		return (char *)(h);
	while (i < (int)len && h[i] != '\0')
	{
		j = 0;
		while (i < (int)len && j < (int)len && h[i] == n[j])
		{
			i++;
			j++;
			if (n[j] == '\0')
				return ((char *)(h + (i - j)));
		}
		i -= j;
		i++;
	}
	return (0);
}
