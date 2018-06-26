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

void			storing_map_file_into_memory_parser(char *map_file,
				t_god_struct *god)
{
	int		shints[2];
	char	*str;
	char	*line;
	char	*temp;

	shints[0] = open(map_file, O_RDONLY);
	if (shints[0] < 0)
		ft_error_funx();
	str = ft_strdup("");
	line = NULL;
	while ((shints[1] = get_next_line(shints[0], &line) > 0))
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

/*
**	ints[0]		i;
**	ints[1]		j;
**	int[2]		number_of_rows;
**	int[3]		number_of_cols;
*/

void			apply_atoi_2_strings_and_store(char *map_data_after_parsing,
					t_god_struct *god)
{
	god->ints[0] = -1;
	god->ints[4] = -1;
	god->n_s_m = ft_strsplit(map_data_after_parsing, '\n');
	god->ints[2] = len_star_star(god->n_s_m);
	god->height = god->ints[2];
	god->stored_map = (int **)malloc(sizeof(int *) * god->ints[2]);
	while (god->n_s_m[++god->ints[0]])
	{
		god->s_s_s = ft_strsplit(god->n_s_m[god->ints[0]], ' ');
		god->ints[3] = len_star_star(god->s_s_s);
		god->stored_map[god->ints[0]] =
				(int *)malloc(sizeof(int) * god->ints[3]);
		god->ints[1] = -1;
		while (++god->ints[1] < god->ints[3])
			god->stored_map[god->ints[0]][god->ints[1]] =
					ft_atoi(god->s_s_s[god->ints[1]]);
		free_array((void**)(god->s_s_s));
		if (god->ints[4] != -1 && god->ints[3] != god->ints[4])
			ft_bad_format();
		god->ints[4] = god->ints[3];
	}
	god->width = god->ints[3];
	free_array((void**)(god->n_s_m));
	free(map_data_after_parsing);
}
