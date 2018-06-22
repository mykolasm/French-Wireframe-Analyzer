/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarcink <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 09:52:56 by mmarcink          #+#    #+#             */
/*   Updated: 2018/06/20 14:53:05 by mmarcink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_ko_newline(char **str, char **line)
{
	char *temp;

	if (!(temp = ft_strchr(*str, '\n')))
		return (0);
	*line = ft_strsub(*str, 0, temp - *str);
	ft_strncpy(*str, temp + 1, ft_strlen(temp));
	return (1);
}

int		ft_join(int const fd, char *dat_file_data[FD_LIMIT], char **line)
{
	int		ret;
	char	buf[BUFF_SIZE + 1];
	char	*temp;

	if (dat_file_data[fd] == NULL)
		if (!(dat_file_data[fd] = ft_strnew(1)) || (read(fd, buf, 0) < 0))
			return (-1);
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		temp = dat_file_data[fd];
		if (!(dat_file_data[fd] = ft_strjoin(dat_file_data[fd], buf)))
			return (-1);
		ft_strdel((char **)&temp);
		if (ft_ko_newline(&dat_file_data[fd], line))
			return (1);
	}
	if (dat_file_data[fd] && !(dat_file_data[fd][0] == '\0'))
	{
		*line = dat_file_data[fd];
		dat_file_data[fd] = NULL;
		return (1);
	}
	return (0);
}

int		get_next_line(int const fd, char **line)
{
	static char	*file_data[FD_LIMIT];
	int			gnl_return_val;

	if (line == NULL || fd < 0 || fd > FD_LIMIT)
		return (-1);
	if (file_data[fd] && ft_ko_newline(&file_data[fd], line))
		return (1);
	gnl_return_val = ft_join(fd, file_data, line);
	return (gnl_return_val);
}
