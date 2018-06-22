/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarcink <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 15:44:03 by mmarcink          #+#    #+#             */
/*   Updated: 2018/03/07 15:44:03 by mmarcink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_itoa(int n)
{
	char *s;

	if (!(s = (char *)ft_memalloc(sizeof(*s) + (ft_num_digits(n)))))
		return (NULL);
	ft_what_base(n, s, ft_num_digits(n) - 1);
	s[ft_num_digits(n)] = '\0';
	return (s);
}
