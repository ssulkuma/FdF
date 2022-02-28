/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssulkuma <ssulkuma@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 16:51:12 by ssulkuma          #+#    #+#             */
/*   Updated: 2022/02/28 19:06:59 by ssulkuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	free_map(t_map *map)
{
	printf("%d\n", map->rows);
	printf("%d\n", map->cols);
	while (map->rows >= 0)
	{
		free(map->map[map->cols]);
		map->rows--;
	}
	free(map->map);
	exit(0);
}

void	error(const char *str)
{
	perror(str);
	exit(1);
}

int	main(int argc, char **argv)
{
	t_mlx	mlx;
	t_map	map;

	if (argc != 2)
	{
		ft_putendl("Usage: ./fdf [map_file]");
		return (1);
	}
	read_map(argv[1], &map);
	mlx.connection = mlx_init();
	if (!mlx.connection)
		error("error");
	mlx.window = mlx_new_window(mlx.connection, 1000, 1000, "FdF");
	if (!mlx.window)
		error("error");
	draw(&mlx, &map);
	events(&mlx);
	mlx_loop(mlx.connection);
	free_map(&map);
	return (0);
}
