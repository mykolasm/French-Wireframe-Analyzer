/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarcink <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/22 09:06:21 by mmarcink          #+#    #+#             */
/*   Updated: 2018/06/22 09:06:21 by mmarcink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	int		e_i;
	char	*trimmed_str;

	if (!s)
		return (NULL);
	while (*s && is_ws(*s))
		s++;
	e_i = ft_strlen(s) - 1;
	while (is_ws(*(s + e_i)))
		e_i--;
	if (!*s)
		return (ft_strnew(1));
	if (!(trimmed_str = ft_strsub(s, 0, e_i + 1)))
		return (NULL);
	return (trimmed_str);
}
