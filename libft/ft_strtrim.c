/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarcink <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 17:52:29 by mmarcink          #+#    #+#             */
/*   Updated: 2018/03/05 17:52:29 by mmarcink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strtrim(char const *s)
{
	int		end;
	char	*trim_str;

	if (!s)
		return (NULL);
	while (*s && ft_is_wspace(*s))
		s++;
	end = ft_strlen(s) - 1;
	while (ft_is_wspace(*(s + end)))
		end--;
	if (!*s)
		return (ft_strnew(1));
	if (!(trim_str = ft_strsub(s, 0, end + 1)))
		return (NULL);
	return (trim_str);
}
