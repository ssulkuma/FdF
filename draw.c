/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssulkuma <ssulkuma@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 19:05:50 by ssulkuma          #+#    #+#             */
/*   Updated: 2022/02/25 12:44:09 by ssulkuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	draw_pixel_to_image(t_mlx *mlx, int x, int y, int color)
{
	char	*dest;

	dest = mlx->address + (y * mlx->line_len + x * (mlx->bits_per_pixel / 8));
	*(unsigned int *)dest = color;
}

static float	get_max_delta(float step_x, float step_y)
{
	if (step_x < 0)
		step_x *= -1;
	if (step_y < 0)
		step_y *= -1;
	if (step_x > step_y)
		return (step_x);
	else
		return (step_y);
}

static void	draw_algorithm(t_mlx *mlx, t_map *map)
{
	float	step_x;
	float	step_y;
	float	max_delta;

	mlx->start_z = map->map[(int)mlx->start_y][(int)mlx->start_x];
	mlx->end_z = map->map[(int)mlx->end_y][(int)mlx->end_x];
	step_x = mlx->end_x - mlx->start_x;
	step_y = mlx->end_y - mlx->start_x;
	max_delta = get_max_delta(step_x, step_y);
	step_x /= max_delta;
	step_y /= max_delta;
	mlx->image = mlx_new_image(mlx->connection, 500, 500);
	mlx->address = mlx_get_data_addr(mlx->image, &mlx->bits_per_pixel,
			&mlx->line_len, &mlx->endian);
	while (mlx->start_x - mlx->end_x || mlx->start_y - mlx->end_y)
	{
		draw_pixel_to_image(mlx, mlx->start_x, mlx->start_y, 0x00FF0000);
		mlx->start_x += step_x;
		mlx->start_y += step_y;
		if (mlx->start_x < 0 || mlx->start_x > 500 || mlx->start_y < 0 || mlx->start_y > 500)
			break ;
	}
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
