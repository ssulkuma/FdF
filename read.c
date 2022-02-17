/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssulkuma <ssulkuma@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 13:22:02 by ssulkuma          #+#    #+#             */
/*   Updated: 2022/02/17 16:54:42 by ssulkuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	count_cols(char *line)
{
	int	index;
	int	count;

	index = 0;
	count = 1;
	if (line[index] == '\0')
		count = 0;
	while (line[index] != '\0')
	{
		if (line[index] == ' ')
			count++;
		index++;
	}
	return (count);
}

static void	get_map_size(int fd)
{
	int		ret;
	int		cols;
	char	*line;
	t_map	map;

	line = NULL;
	map.rows = 0;
	map.cols = 0;
	while (1)
	{
		ret = get_next_line(fd, &line);
		if (ret > 0)
		{
			cols = count_cols(line);
			if (map.cols < cols)
				map.cols = cols;
			map.rows++;
		}
		else
			break ;
	}
}

int	read_map(char *map_file)
{
	int		fd;

	fd = open(map_file, O_RDONLY);
	if (fd == -1)
		return (-1);
	get_map_size(fd);
	close(fd);
	return (0);
}
