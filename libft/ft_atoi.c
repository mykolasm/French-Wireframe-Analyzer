/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarcink <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/22 09:06:09 by mmarcink          #+#    #+#             */
/*   Updated: 2018/06/22 09:06:09 by mmarcink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int					i;
	int					is_neg;
	unsigned long long	res;

	is_neg = 0;
	i = 0;
	res = 0;
	while (str[i] && (str[i] == '\n' || str[i] == '\t' || str[i] == '\r' ||
					str[i] == '\v' || str[i] == ' ' || str[i] == '\f'))
		i++;
	if (str[i] == '-')
		is_neg = 1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] && str[i] <= '9' && str[i] >= '0')
	{
		res = (res * 10) + (str[i] - '0');
		if (res > 9223372036854775807)
			return ((is_neg != 1) ? -1 : 0);
		i++;
	}
	if (is_neg == 1)
		return (-res);
	else
		return (res);
}
