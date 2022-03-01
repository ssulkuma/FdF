/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssulkuma <ssulkuma@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 16:51:12 by ssulkuma          #+#    #+#             */
/*   Updated: 2022/03/01 17:56:57 by ssulkuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	free_map(t_mlx *mlx)
{
	printf("%d\n", mlx->rows);
	printf("%d\n", mlx->cols);
	while (mlx->rows > 0)
	{
		free(mlx->map[mlx->rows]);
		mlx->rows--;
	}
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
