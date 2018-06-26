/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fast_line_algo.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarcink <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 18:17:02 by mmarcink          #+#    #+#             */
/*   Updated: 2018/06/25 18:17:02 by mmarcink         ###   ########.fr       */
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
