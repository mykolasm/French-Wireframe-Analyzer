/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooking.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarcink <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 11:59:50 by mmarcink          #+#    #+#             */
/*   Updated: 2018/06/25 11:59:50 by mmarcink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	arrow_keys_and_zoom(int key, t_god_struct *god)
{
	if (key == 126)
		god->y_loc++;
	else if (key == 125)
		god->y_loc--;
	else if (key == 123)
		god->x_loc++;
	else if (key == 124)
		god->x_loc--;
	else
		return (0);
	return (1);
}

int	alphabet_keys(int key, t_god_struct *god)
{
	if (key == 53)
		exit(1);
	else if (key == 0)
		god->infinite_projections_a++;
	else if (key == 17)
		god->infinite_projections_t++;
	else if (key == 6)
		god->z_rotation--;
	else if (key == 7)
		god->x_rotation++;
	else if (key == 16)
		god->y_rotation++;
	else if (key == 11)
		god->boost_z++;
	else if (key == 45)
		god->boost_z--;
	else
		return (0);
	return (1);
}

int	key_handler(int key, t_god_struct *god)
{
	if (arrow_keys_and_zoom(key, god) || alphabet_keys(key, god))
		ft_draw(god);
	ft_putnbr(key);
	return (0);
}
