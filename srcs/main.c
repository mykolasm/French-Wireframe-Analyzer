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

t_god_struct	*create_god_struct(int width, int height, void *mlx,
				void *window)
{
	t_god_struct *temp;

	temp = ft_memalloc(sizeof(t_god_struct));
	temp->width = width;
	temp->height = height;
	temp->mlx = mlx;
	temp->window = window;
	temp->rotation_parameters[0] = 30;
	temp->rotation_parameters[1] = 120;
	temp->x_rotation = 0;
	temp->y_rotation = 0;
	temp->z_rotation = 0;
	temp->x_loc = 0;
	temp->y_loc = 0;
	temp->infinite_projections_a = 0;
	temp->infinite_projections_t = 0;
	temp->zoom = 1;
	temp->boost_z = 1;
	return (temp);
}

void			display_controls(void)
{
	ft_putendl("CONTROLS:\n\
Translation:\n\
	UP: Down arrow key\n\
	DOWN: Up arrow key\n\
	RIGHT: Left arrow key\n\
	LEFT: Right arrow key\n\
	Trolololol\n\
Rotation:\n\
	X: X key\n\
	Y: Y key\n\
	Z: Z key\n\
Zoom:\n\
	IN: Mouse forward\n\
	OUT: Mouse backward");
}

void			ft_draw(t_god_struct *god)
{
	mlx_clear_window(god->mlx, god->window);
	loop_stored_map_draw_x_lines(god);
}

int				mouse_handler(int key, int x, int y, t_god_struct *god)
{
	ft_putnbr(x);
	ft_putnbr(y);
	if (key == 5)
	{
		god->zoom += .1;
		ft_draw(god);
	}
	if (key == 4)
	{
		god->zoom -= .1;
		ft_draw(god);
	}
	ft_putnbr(key);
	return (0);
}

int				main(int argc, char **argv)
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
		display_controls();
		god = create_god_struct(-1, -1, mlx, window);
		storing_map_file_into_memory_parser(argv[1], god);
		loop_stored_map_draw_x_lines(god);
		mlx_hook(window, 2, 0, key_handler, god);
		mlx_hook(window, 4, 0, mouse_handler, god);
		mlx_loop(mlx);
	}
	return (0);
}
