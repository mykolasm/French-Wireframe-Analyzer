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

void		draw_3d_line_for_norm1(t_god_struct *god, int ints[4], int mv)
{
	mlx_draw_3d_line(god, (t_td_point){ints[1] * (mv), ints[2]
				* (mv), god->stored_map[ints[2]][ints[1]] * (mv)},
(t_td_point){ints[1] * (mv), ints[0] * (mv),
god->stored_map[ints[0]][ints[1]] * (mv)}, 0xFFFFFF);
}

void		draw_3d_line_for_norm2(t_god_struct *god, int ints[4], int mv)
{
	mlx_draw_3d_line(god, (t_td_point){ints[3] * (mv),
				ints[0] * (mv), god->stored_map[ints[0]][ints[3]] * (mv)},
				(t_td_point){ints[1] * (mv), ints[0] * (mv),
				god->stored_map[ints[0]][ints[1]] * (mv)}, 0xFFFFFF);
}

void		loop_stored_map_draw_x_lines(t_god_struct *god)
{
	int	ints[4];
	int	mv;

	ints[0] = -1;
	ints[2] = ints[0];
	ints[3] = ints[1];
	if ((god->width * god->width) < WIDTH)
		mv = WIDTH / (god->width * god->width);
	else
		mv = 1;
	while (++ints[0] < god->height)
	{
		ints[1] = -1;
		while (++ints[1] < god->width)
		{
			if (ints[0] != 0)
				draw_3d_line_for_norm1(god, ints, mv);
			if (ints[1] != 0)
				draw_3d_line_for_norm2(god, ints, mv);
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
		td_point_1[2], god);
	two_d_point2 = magic_function_plots_2d_from_3d(td_point_2[0], td_point_2[1],
		td_point_2[2], god);
	super_fast_line_algo(god, two_d_point1, two_d_point2, color);
}
