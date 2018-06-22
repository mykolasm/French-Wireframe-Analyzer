/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarcink <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/22 09:06:20 by mmarcink          #+#    #+#             */
/*   Updated: 2018/06/22 09:06:20 by mmarcink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	int i;
	int j;

	i = 0;
	if (needle[0] == '\0')
		return (char *)(haystack);
	while (i < (int)len && haystack[i] != '\0')
	{
		j = 0;
		while (i < (int)len && j < (int)len && haystack[i] == needle[j])
		{
			i++;
			j++;
			if (needle[j] == '\0')
				return ((char *)(haystack + (i - j)));
		}
		i -= j;
		i++;
	}
	return (0);
}
