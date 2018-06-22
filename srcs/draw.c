/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarcink <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/21 11:39:39 by mmarcink          #+#    #+#             */
/*   Updated: 2018/06/21 11:39:39 by mmarcink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
** Credits to Po-Han Lin for fast and fancy line algo
** http://www.edepot.com/algorithm.html
*/

void		y_longer(t_god_struct *gl, t_2d_point pt_i, int para[7])
{
	if (para[3] > 0)
	{
		para[3] += pt_i[1];
		para[6] = 0x8000 + ((int)pt_i[0] << 16);
		while (pt_i[1] <= para[3])
		{
			mlx_pixel_put(gl->mlx, gl->window, para[6] >> 16, pt_i[1], para[0]);
			para[6] += para[4];
			++pt_i[1];
		}
		return ;
	}
	para[3] += pt_i[1];
	para[6] = 0x8000 + ((int)pt_i[0] << 16);
	while (pt_i[1] >= para[3])
	{
		mlx_pixel_put(gl->mlx, gl->window, para[6] >> 16, pt_i[1], para[0]);
		para[6] -= para[4];
		--pt_i[1];
	}
	return ;
}

void		y_not_longer(t_god_struct *gl, t_2d_point pt_i, int para[7])
{
	if (para[3] > 0)
	{
		para[3] += pt_i[0];
		para[6] = 0x8000 + ((int)pt_i[1] << 16);
		while (pt_i[0] <= para[3])
		{
			mlx_pixel_put(gl->mlx, gl->window, pt_i[0], para[6] >> 16, para[0]);
			para[6] += para[4];
			++pt_i[0];
		}
		return ;
	}
	para[3] += pt_i[0];
	para[6] = 0x8000 + ((int)pt_i[1] << 16);
	while (pt_i[0] >= para[3])
	{
		mlx_pixel_put(gl->mlx, gl->window, pt_i[0], para[6] >> 16, para[0]);
		para[6] -= para[4];
		--pt_i[0];
	}
}

/*
** para[0] = color, para[1] = y_longer, para[2] = shortLen, para[3] = longLen,
** para[4] = decInc, para[5] = swap, para[6] = j
*/

void		super_fast_line_algo(t_god_struct *gl, t_2d_point pt_i,
				t_2d_point pt_f, int color)
{
	int	para[7];

	para[0] = color;
	para[1] = 0;
	para[2] = pt_f[1] - pt_i[1];
	para[3] = pt_f[0] - pt_i[0];
	if (abs(para[2]) > abs(para[3]))
	{
		para[5] = para[2];
		para[2] = para[3];
		para[3] = para[5];
		para[1] = 1;
	}
	if (para[3] == 0)
		para[4] = 0;
	else
		para[4] = (para[2] << 16) / para[3];
	if (para[1])
		return (y_longer(gl, pt_i, para));
	return (y_not_longer(gl, pt_i, para));
}

void		loop_stored_map_draw_x_lines(t_god_struct *god)
{
	int ints[4];

	ints[0] = -1;
	ints[2] = ints[0];
	ints[3] = ints[1];
	while (++ints[0] < god->height)
	{
		ints[1] = -1;
		while (++ints[1] < god->width)
		{
			if (ints[0] != 0)
			{
				mlx_draw_3d_line(god, (t_td_point){ints[1] * 25, ints[2] * 25,
god->stored_map[ints[2]][ints[1]] * 2}, (t_td_point){ints[1] * 25, ints[0] * 25,
god->stored_map[ints[0]][ints[1]] * 2}, 0xFFFFFF);
			}
			if (ints[1] != 0)
				mlx_draw_3d_line(god, (t_td_point){ints[3] * 25, ints[0] * 25,
god->stored_map[ints[0]][ints[3]] * 2}, (t_td_point){ints[1] * 25,
ints[0] * 25, god->stored_map[ints[0]][ints[1]] * 2}, 0xFFFFFF);
			ints[3] = ints[1];
		}
		ints[2] = ints[0];
	}
}

void		mlx_draw_3d_line(t_god_struct *god, t_td_point td_point_1,
			t_td_point td_point_2, int color)
{
	t_2d_point	two_d_point1;
	t_2d_point	two_d_point2;

	two_d_point1 = magic_function_plots_2d_from_3d(td_point_1[0], td_point_1[1],
		td_point_1[2]);
	two_d_point2 = magic_function_plots_2d_from_3d(td_point_2[0], td_point_2[1],
		td_point_2[2]);
	ft_putnbr(two_d_point1[0]);
	ft_putnbr(two_d_point1[1]);
	ft_putnbr(two_d_point2[0]);
	ft_putnbr(two_d_point2[1]);
	super_fast_line_algo(god, two_d_point1, two_d_point2, color);
}

/*
** check for leaks
*/
