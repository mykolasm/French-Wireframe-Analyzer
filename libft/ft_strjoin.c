/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarcink <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 17:33:14 by mmarcink          #+#    #+#             */
/*   Updated: 2018/03/05 17:33:14 by mmarcink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strjoin(char const *s1, char const *s2)
{
	char	*new_str;

	if (!s1 || !s2 || !(new_str = ft_strnew(ft_strlen(s1) + ft_strlen(s2))))
		return (NULL);
	new_str = ft_strcpy(new_str, s1);
	return (ft_strcat(new_str, s2));
}
