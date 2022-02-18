/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssulkuma <ssulkuma@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 13:22:02 by ssulkuma          #+#    #+#             */
/*   Updated: 2022/02/18 11:31:18 by ssulkuma         ###   ########.fr       */
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

static void	get_map_size(int fd, t_map *map)
{
	int		ret_value;
	int		cols;
	char	*line;

	line = NULL;
	map->rows = 0;
	map->cols = 0;
	while (1)
	{
		ret_value = get_next_line(fd, &line);
		if (ret_value > 0)
		{
			cols = count_cols(line);
			if (map->cols < cols)
				map->cols = cols;
			free(line);
			map->rows++;
		}
		else
			break ;
	}
}

static int	**create_map(t_map *map)
{
	int		**matrix;
	int		index;

	matrix = (int **)malloc(sizeof(int *) * (map->rows + 1));
	if (!matrix)
		return (NULL);
	index = 0;
	while (index < map->rows)
	{
		matrix[index] = (int *)malloc(sizeof(int) * (map->cols + 1));
		if (!matrix[index])
		{
			while (index >= 0)
			{
				ft_memdel((void **)matrix[index--]);
				ft_memdel((void **)matrix);
				return (NULL);
			}
		}
		index++;
	}
	return (matrix);
}

int	read_map(char *map_file)
{
	int		fd;
	t_map	map;

	fd = open(map_file, O_RDONLY);
	if (fd == -1)
		return (-1);
	get_map_size(fd, &map);
	map.map = create_map(&map);
	if (!map.map)
		return (-1);
	close(fd);
	return (0);
}
