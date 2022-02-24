/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssulkuma <ssulkuma@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 19:05:50 by ssulkuma          #+#    #+#             */
/*   Updated: 2022/02/24 18:23:11 by ssulkuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	draw_pixel_to_image(t_mlx *mlx, int x, int y, int color)
{
	char	*dest;

	dest = mlx->address + (y * mlx->line_len + x * (mlx->bits_per_pixel / 8));
	*(unsigned int *)dest = color;
}

static void	draw_algorithm(t_mlx *mlx, t_map *map)
{
	float	step_x;
	float	step_y;

	mlx->start_z = map->map[(int)mlx->start_y][(int)mlx->start_x];
	mlx->end_z = map->map[(int)mlx->end_y][(int)mlx->end_x];
	step_x = mlx->end_x - mlx->start_x;
	step_y = mlx->end_y - mlx->start_x;
	mlx->image = mlx_new_image(mlx->connection, 500, 500);
	mlx->address = mlx_get_data_addr(mlx->image, &mlx->bits_per_pixel,
			&mlx->line_len, &mlx->endian);
	draw_pixel_to_image(mlx, 10, 10, 0x00FF0000);
}

void	draw(t_mlx *mlx, t_map *map)
{
	int	x;
	int	y;

	y = 0;
	while (y < map->rows)
	{
		x = 0;
		while (x < map->cols)
		{
			if (x < map->cols - 1)
			{
				mlx->start_x = x;
				mlx->start_y = y;
				mlx->end_x = x + 1;
				mlx->end_y = y;
				draw_algorithm(mlx, map);
			}
			if (y < map->rows - 1)
			{
				mlx->start_x = x;
				mlx->start_y = y;
				mlx->end_x = x;
				mlx->end_y = y + 1;
				draw_algorithm(mlx, map);
			}
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(mlx->connection, mlx->window, mlx->image, 0, 0);
}
