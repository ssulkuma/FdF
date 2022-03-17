/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssulkuma <ssulkuma@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 19:08:21 by ssulkuma          #+#    #+#             */
/*   Updated: 2022/03/17 11:48:22 by ssulkuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	draw_pixel_to_image(t_mlx *mlx, int x, int y, int color)
{
	char	*pixel;

	if (mlx->start_x >= 0 && mlx->start_x < 1000 && mlx->start_y >= 0
		&& mlx->start_y < 1000)
	{
		pixel = mlx->address + (y * mlx->line_len + \
			x * (mlx->bits_per_pixel / 8));
		*(unsigned int *)pixel = color;
	}
}

static void	draw_line(t_mlx *mlx, float step_x, float step_y, float max_delta)
{
	int	color_add;

	color_add = 0;
	while ((int)(mlx->start_x - mlx->end_x) || (int)(mlx->start_y - mlx->end_y))
	{
		draw_color(mlx, max_delta, color_add);
		draw_pixel_to_image(mlx, mlx->start_x, mlx->start_y, mlx->color);
		mlx->start_x += step_x;
		mlx->start_y += step_y;
		color_add++;
	}
}

static void	draw_algorithm(t_mlx *mlx)
{
	float	step_x;
	float	step_y;
	float	max_delta;

	mlx->start_z = mlx->map[(int)mlx->start_y][(int)mlx->start_x];
	mlx->end_z = mlx->map[(int)mlx->end_y][(int)mlx->end_x];
	if (mlx->start_z > MAX_ALTITUDE || mlx->start_z < MIN_ALTITUDE
		|| mlx->end_z > MAX_ALTITUDE || mlx->end_z < MIN_ALTITUDE)
		return ;
	add_zoom(mlx);
	center_position(mlx);
	if (mlx->projection == 1)
		isometric_projection(mlx);
	step_x = mlx->end_x - mlx->start_x;
	step_y = mlx->end_y - mlx->start_y;
	max_delta = get_max_delta(step_x, step_y);
	step_x /= max_delta;
	step_y /= max_delta;
	draw_line(mlx, step_x, step_y, max_delta);
}

static void	draw_setup(t_mlx *mlx, int x, int y)
{
	if (x < mlx->cols - 1)
	{
		mlx->start_x = x;
		mlx->start_y = y;
		mlx->end_x = x + 1;
		mlx->end_y = y;
		draw_algorithm(mlx);
	}
	if (y < mlx->rows - 1)
	{
		mlx->start_x = x;
		mlx->start_y = y;
		mlx->end_x = x;
		mlx->end_y = y + 1;
		draw_algorithm(mlx);
	}
}

void	draw(t_mlx *mlx)
{
	int	x;
	int	y;

	mlx->image = mlx_new_image(mlx->connection, 1000, 1000);
	mlx->address = mlx_get_data_addr(mlx->image, &mlx->bits_per_pixel,
			&mlx->line_len, &mlx->endian);
	y = 0;
	while (y < mlx->rows)
	{
		x = 0;
		while (x < mlx->cols)
		{
			draw_setup(mlx, x, y);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(mlx->connection, mlx->window, mlx->image, 0, 0);
	menu(mlx);
}
