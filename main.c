/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssulkuma <ssulkuma@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 16:51:12 by ssulkuma          #+#    #+#             */
/*   Updated: 2022/03/03 17:43:55 by ssulkuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	check_color_arguments(t_mlx *mlx, char **argv)
{
	int	red;
	int	green;
	int	blue;

	if (argv[2] && argv[3] && argv[4])
	{
		red = ft_atoi(argv[2]);
		green = ft_atoi(argv[3]);
		blue = ft_atoi(argv[4]);
		if (red >= 0 && red <= 255 && green >= 0 && green <= 255
			&& blue >= 0 && blue <= 255)
		{
			mlx->color_r = red;
			mlx->color_g = green;
			mlx->color_b = blue;
		}
		else
			ft_putendl("Invalid colorvalues, using default colors.");
	}
}

static void	struct_intel(t_mlx *mlx, char **argv)
{
	mlx->color_t = 0;
	mlx->color_r = 255;
	mlx->color_g = 0;
	mlx->color_b = 0;
	check_color_arguments(mlx, argv);
	mlx->zoom = 30;
	mlx->position_x = 500;
	mlx->position_y = 250;
}

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

	if (argc == 2 || argc == 5)
		;
	else
	{
		ft_putendl("Usage: ./fdf [map_file] [red color (0-255)] \
[green color (0-255)] [blue color (0-255)]");
		ft_putendl("If no colorvalues are given, default colors will be used.");
		return (1);
	}
	struct_intel(&mlx, argv);
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
