/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarcink <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/19 13:48:49 by mmarcink          #+#    #+#             */
/*   Updated: 2018/06/19 13:48:49 by mmarcink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		main(int argc, char **argv)
{
	void			*mlx;
	void			*window;
	int				test_color;
	t_god_struct	*god;

	test_color = 0xFFFFFF;
	if (argc == 2)
	{
		mlx = mlx_init();
		window = mlx_new_window(mlx, WIDTH, HEIGHT, "FdF Wireframe Visualizer");
		god = create_god_struct(-1, -1, mlx, window);
		storing_map_file_into_memory_parser(argv[1], god);
		loop_stored_map_draw_x_lines(god);
		mlx_loop(mlx);
	}
	return (0);
}
