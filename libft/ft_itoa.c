/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarcink <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/22 09:06:11 by mmarcink          #+#    #+#             */
/*   Updated: 2018/06/22 09:06:11 by mmarcink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_itoa(int n)
{
	char *str;

	if (!(str = (char *)ft_memalloc(sizeof(*str) + (get_num_digi(n)))))
		return (NULL);
	put_base(n, str, get_num_digi(n) - 1);
	str[get_num_digi(n)] = '\0';
	return (str);
}
