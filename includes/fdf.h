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
# define WIDTH 2000
# define HEIGHT 1000

typedef struct		s_god_struct
{
	int		rotation_parameters[2];
	int		width;
	int		height;
	int		**stored_map;
	void	*mlx;
	void	*window;
	double	x_loc;
	double	y_loc;
	double	x_rotation;
	double	y_rotation;
	double	z_rotation;
	double	infinite_projections_a;
	double	infinite_projections_t;
	double	boost_z;
	double	zoom;
	char	**n_s_m;
	char	**s_s_s;
	int		ints[5];
}					t_god_struct;
typedef int			t_2d_point __attribute__((vector_size(2 * sizeof(int))));
typedef int			t_td_point __attribute__((vector_size(3 * sizeof(int))));
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
t_2d_point			magic_function_plots_2d_from_3d(int x, int y, int z,
					t_god_struct *god);
void				mlx_draw_3d_line(t_god_struct *god,
					t_td_point td_point_1, t_td_point td_point_2, int color);
void				mlx_draw_2d_line(t_god_struct *god, t_2d_point two_d_point1,
					t_2d_point two_d_point2, int color);
int					mouse_handler(int key, int x, int y, t_god_struct *god);
int					arrow_keys_and_zoom(int key, t_god_struct *god);
int					alphabet_keys(int key, t_god_struct *god);
int					key_handler(int key, t_god_struct *god);
void				ft_draw(t_god_struct *god);
void				y_longer(t_god_struct *gl, t_2d_point pt_i, int para[7]);
void				y_not_longer(t_god_struct *gl,
					t_2d_point pt_i, int para[7]);
void				draw_3d_line_for_norm1(t_god_struct *god, int ints[4],
					int mv);
void				draw_3d_line_for_norm2(t_god_struct *god, int ints[4],
					int mv);
void				ft_error_funx(void);
int					len_star_star(char **str);
void				ft_bad_format(void);
#endif
