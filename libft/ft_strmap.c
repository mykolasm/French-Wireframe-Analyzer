/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarcink <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 16:51:12 by mmarcink          #+#    #+#             */
/*   Updated: 2018/03/05 16:51:12 by mmarcink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strmap(char const *s, char (*f)(char))
{
	char	*fresh_str;
	size_t	i;

	i = 0;
	if (!f || !s || !(fresh_str = ft_strnew(ft_strlen(s))) || !f || !s)
		return (NULL);
	while (s[i])
	{
		fresh_str[i] = f(s[i]);
		i++;
	}
	return (fresh_str);
}
