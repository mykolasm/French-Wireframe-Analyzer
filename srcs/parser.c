/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarcink <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/20 15:17:05 by mmarcink          #+#    #+#             */
/*   Updated: 2018/06/20 15:17:05 by mmarcink         ###   ########.fr       */
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
	return (temp);
}

void			storing_map_file_into_memory_parser(char *map_file,
				t_god_struct *god)
{
	int		fd;
	int		byte_size;
	char	*str;
	char	*line;
	char	*temp;

	fd = open(map_file, O_RDONLY);
	if (fd < 0)
		str = ft_strdup("");
	line = NULL;
	while ((byte_size = get_next_line(fd, &line) > 0))
	{
		temp = line;
		line = ft_strjoin(line, "\n");
		ft_memdel((void **)&temp);
		temp = str;
		str = ft_strjoin(str, line);
		ft_memdel((void **)&temp);
		if (line)
			ft_memdel((void **)&line);
	}
	if (line)
		ft_memdel((void **)&line);
	apply_atoi_2_strings_and_store(str, god);
}

int				len_star_star(char **str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

/*
**	ints[0]		i;
**	ints[1]		j;
**	int[2]		number_of_rows;
**	int[3]		number_of_cols;
*/

void			apply_atoi_2_strings_and_store(char *map_data_after_parsing,
					t_god_struct *god)
{
	char	**newline_split_map;
	char	**space_split_str;
	int		ints[4];

	ints[0] = -1;
	newline_split_map = ft_strsplit(map_data_after_parsing, '\n');
	ints[2] = len_star_star(newline_split_map);
	god->stored_map = (int **)malloc(sizeof(int *) * ints[2]);
	while (newline_split_map[++ints[0]])
	{
		space_split_str = ft_strsplit(newline_split_map[ints[0]], ' ');
		ints[3] = len_star_star(space_split_str);
		god->stored_map[ints[0]] = (int *)malloc(sizeof(int) * ints[3]);
		ints[1] = -1;
		while (++ints[1] < ints[3])
			god->stored_map[ints[0]][ints[1]] = ft_atoi(space_split_str[ints[1]]);
		free_array((void**)(space_split_str));
	}
	free_array((void**)(newline_split_map));
	god->width = ints[3];
	god->height = ints[2];
}
