/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssulkuma <ssulkuma@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 16:51:12 by ssulkuma          #+#    #+#             */
/*   Updated: 2022/03/02 12:08:57 by ssulkuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	free_map(t_mlx *mlx)
{
	int	index;

	index = 0;
	while (mlx->rows > index)
		free(mlx->map[index++]);
	free(mlx->map);
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

	if (argc != 2)
	{
		ft_putendl("Usage: ./fdf [map_file]");
		return (1);
	}
	mlx.zoom = 30;
	read_map(argv[1], &mlx);
	mlx.connection = mlx_init();
	if (!mlx.connection)
		error("error");
	mlx.window = mlx_new_window(mlx.connection, 1000, 1000, "FdF");
	if (!mlx.window)
		error("error");
	draw(&mlx);
	events(&mlx);
	mlx_loop(mlx.connection);
	return (0);
}
