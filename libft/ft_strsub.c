/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarcink <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/22 09:06:21 by mmarcink          #+#    #+#             */
/*   Updated: 2018/06/22 09:06:21 by mmarcink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*fresh_str;
	size_t	i;

	if (!s || !(fresh_str = ft_strnew(len)))
		return (NULL);
	i = -1;
	while (++i < len)
		*(fresh_str + i) = *(s + start + i);
	return (fresh_str);
}
