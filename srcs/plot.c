/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plot.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarcink <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/20 20:51:48 by mmarcink          #+#    #+#             */
/*   Updated: 2018/06/20 20:51:48 by mmarcink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_2d_point		magic_function_plots_2d_from_3d(int x, int y, int z)
{
	double	angle[5];
	double	cord_hold[3];
	double	two_d_x;
	double	two_d_y;

	angle[0] = 0.0174533 * 30;
	angle[1] = 0.0174533 * 120;
	angle[2] = 0.017453 * 0;
	angle[3] = 0.017453 * 0;
	angle[4] = 0.017453 * 0;
	cord_hold[0] = x;
	x = cord_hold[0] * cos(angle[4]) - y * sin(angle[4]);
	y = cord_hold[0] * sin(angle[4]) + y * cos(angle[4]);
	cord_hold[1] = y;
	y = cord_hold[1] * cos(angle[2]) - z * sin(angle[2]);
	z = cord_hold[1] * sin(angle[2]) + z * cos(angle[2]);
	cord_hold[2] = z;
	z = cord_hold[2] * cos(angle[3]) - x * sin(angle[3]);
	x = cord_hold[2] * sin(angle[3]) + x * cos(angle[3]);
	two_d_x = (x * cos(angle[0]) + y * cos(angle[0] + angle[1]) +
			z * cos(angle[0] - angle[1]));
	two_d_y = (x * sin(angle[0]) + y * sin(angle[0] + angle[1]) +
			z * sin(angle[0] - angle[1]));
	return (t_2d_point){two_d_x + WIDTH / 2, two_d_y + HEIGHT / 2};
}

void			loop_thru_stored_map(t_god_struct *god)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < god->height)
	{
		j = 0;
		while (j < god->width)
		{
			if (god->stored_map[i][j] > 0)
			{
				mlx_pixel_put(god->mlx, god->window, j * 25, i * 25, 0xFFFFFF);
			}
			else if (god->stored_map[i][j] == 0)
			{
				mlx_pixel_put(god->mlx, god->window, j * 25, i * 25, 0xFF3333);
			}
			j++;
		}
		i++;
	}
}
