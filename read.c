/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssulkuma <ssulkuma@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 13:22:02 by ssulkuma          #+#    #+#             */
/*   Updated: 2022/02/21 15:01:14 by ssulkuma         ###   ########.fr       */
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
		{
			count++;
			while (line[index++] == ' ')
				index++;
		}
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
			check_valid_chars(line, fd);
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
				ft_memdel((void **)matrix[index--]);
			ft_memdel((void **)matrix);
			return (NULL);
		}
		ft_bzero(matrix[index], map->cols + 1);
		index++;
	}
	return (matrix);
}

static void	fill_map(char *map_file, int fd, t_map *map)
{
	char	**numbers;
	char	*line;
	int		col;
	int		row;

	line = NULL;
	col = 0;
	row = 0;
	fd = open(map_file, O_RDONLY);
	if (fd == 1)
		error("error");
	while (row < map->rows)
	{
		get_next_line(fd, &line);
		while (col < map->cols)
		{
			numbers = ft_strsplit(line, ' ');
			map->map[row][col] = ft_atoi(numbers[col]);
			col++;
		}
		free(line);
		col = 0;
		row++;
	}
	close(fd);
}

int	read_map(char *map_file)
{
	int		fd;
	t_map	map;

	fd = open(map_file, O_RDONLY);
	if (fd == -1)
		error("error");
	get_map_size(fd, &map);
	map.map = create_map(&map);
	close(fd);
	if (!map.map)
		error("error");
	fill_map(map_file, fd, &map);
	return (0);
}
