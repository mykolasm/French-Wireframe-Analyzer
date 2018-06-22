/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarcink <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/22 09:06:19 by mmarcink          #+#    #+#             */
/*   Updated: 2018/06/22 09:06:19 by mmarcink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*n_str;
	unsigned int	i;

	i = -1;
	if (!f || !s || !(n_str = ft_strnew(ft_strlen(s))))
		return (NULL);
	while (*(s + ++i))
		*(n_str + i) = f(i, *(s + i));
	return (n_str);
}
