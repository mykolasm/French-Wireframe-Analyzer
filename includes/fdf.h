/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarcink <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 14:03:03 by mmarcink          #+#    #+#             */
/*   Updated: 2018/02/26 14:03:03 by mmarcink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "libft.h"
# include "mlx.h"
# include <math.h>
# include <time.h>
# define WIDTH 1280
# define HEIGHT 1280

typedef struct		s_god_struct
{
	int		width;
	int		height;
	int		**stored_map;
	void	*mlx;
	void	*window;
}					t_god_struct;
typedef int			t_2d_point __attribute__((vector_size(2 * sizeof(int))));
t_god_struct		*create_god_struct(int width, int height, void *mlx,
					void *window);
void				storing_map_file_into_memory_parser(char *map_file,
					t_god_struct *god);
void				apply_atoi_2_strings_and_store(char *map_data_after_parsing,
					t_god_struct *god);
void				print_int_star_star(int **test, int width, int height);
void				loop_thru_stored_map(t_god_struct *god);
void				loop_stored_map_draw_x_lines(t_god_struct *god);
void				mlx_draw_line(t_god_struct *god, int x0, int y0, int x1,
					int y1, int color);
void				loop_stored_map_draw_y_lines(t_god_struct *god);
t_2d_point			magic_function_plots_2d_from_3d(int x, int y, int z);
void				mlx_draw_3d_line(t_god_struct *god, int x0, int y0, int z0,
					int x1, int y1, int z1, int color);
void				mlx_draw_2d_line(t_god_struct *god, t_2d_point two_d_point1,
					t_2d_point two_d_point2, int color);

#endif
