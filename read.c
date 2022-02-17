/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssulkuma <ssulkuma@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 13:22:02 by ssulkuma          #+#    #+#             */
/*   Updated: 2022/02/17 14:35:34 by ssulkuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	count_rows(int fd, char *line)
{
	int		rows;

	rows = 1;
	while (line != NULL)
	{
		get_next_line(fd, &line);
		rows++;
	}
	return (rows);
}

int	read_map(char *map_file)
{
	int		fd;
	char	*line;
	t_map	map;

	fd = open(map_file, O_RDONLY);
	if (fd == -1)
		return (-1);
	get_next_line(fd, &line);
	if (!line)
		return (-1);
	map.rows = count_rows(fd, line);
	close(fd);
	return (0);
}
