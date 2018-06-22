/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarcink <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/01 10:46:21 by mmarcink          #+#    #+#             */
/*   Updated: 2018/03/01 10:46:21 by mmarcink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_atoi(const char *str)
{
	unsigned int	i;
	int				sign;
	long long		answer;

	i = 0;
	sign = 1;
	answer = 0;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\v' ||
		str[i] == '\f' || str[i] == '\r' || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (ft_isdigit(str[i]))
	{
		if (answer >= 922337203685477580 && (str[i] - '0') > 7)
			return (sign == -1 ? 0 : -1);
		answer = (answer * 10) + (str[i] - '0');
		i++;
	}
	return ((int)(answer * sign));
}
