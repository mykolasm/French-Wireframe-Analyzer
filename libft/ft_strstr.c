/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarcink <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 19:37:02 by mmarcink          #+#    #+#             */
/*   Updated: 2018/02/26 19:37:02 by mmarcink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** AKA locate a substring
** return a (char *) cast because the func name returns (char*)
** haystack + i is returned because thats the starting point of hay
** + i indexes of the substring @ position i of the main string
** array.
** Also, the ending point is when substring needle[j] == '\0'
** return null as a required condition of the man documentation
*/

#include "libft.h"

char		*ft_strstr(const char *haystack, const char *needle)
{
	int i;
	int j;

	i = 0;
	if (needle[0] == '\0' && haystack[0] == '\0')
		return ((char *)haystack);
	while (haystack[i] != '\0')
	{
		j = 0;
		while (needle[j] != '\0' && haystack[i + j] == needle[j])
			j++;
		if (needle[j] == '\0')
			return ((char *)haystack + i);
		i++;
	}
	return (NULL);
}
