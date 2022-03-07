/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_02.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssulkuma <ssulkuma@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 19:02:28 by ssulkuma          #+#    #+#             */
/*   Updated: 2022/03/07 18:40:04 by ssulkuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	add_zoom(t_mlx *mlx)
{
	mlx->start_x *= mlx->zoom;
	mlx->start_y *= mlx->zoom;
	mlx->end_x *= mlx->zoom;
	mlx->end_y *= mlx->zoom;
}

void	isometric_projection(t_mlx *mlx)
{
	mlx->start_x = (mlx->start_x - mlx->start_y) * cos(1);
	mlx->start_y = (mlx->start_x + mlx->start_y) * sin(1) - mlx->start_z;
	mlx->end_x = (mlx->end_x - mlx->end_y) * cos(1);
	mlx->end_y = (mlx->end_x + mlx->end_y) * sin(1) - mlx->end_z;
}

void	center_position(t_mlx *mlx)
{
	mlx->start_x += mlx->position_x;
	mlx->start_y -= mlx->position_y;
	mlx->end_x += mlx->position_x;
	mlx->end_y -= mlx->position_y;
}

int	get_color(t_mlx *mlx)
{
	return (mlx->color_t << 24 | mlx->color_r << 16 | mlx->color_g << 8
		| mlx->color_b);
}

void	draw_color(t_mlx *mlx, float max_delta)
{
	static float	red;
	static float	green;
	static float	blue;

	if (mlx->start_z == 0 && mlx->end_z == 0)
		mlx->color = 0x00FFFFFF;
	else if (mlx->start_z != 0 && mlx->end_z != 0 && mlx->start_z == mlx->end_z)
		mlx->color = mlx->top_color;
	else
	{
		if (red || green || blue)
			;
		else
		{
			red = (255 - mlx->color_r) / max_delta;
			green = (255 - mlx->color_g) / max_delta;
			blue = (255 - mlx->color_b) / max_delta;
		}
		printf("%s%.5f\n", "RED ", red);
		printf("%s%.5f\n", "GREEN ", green);
		printf("%s%.5f\n", "BLUE ", blue);
		printf("%s%.5f\n", "MAX DELTA ", max_delta);
		mlx->color_r = 255 + ((int)red * (int)mlx->start_y);
		mlx->color_g = 255 + ((int)green * (int)mlx->start_y);
		mlx->color_b = 255 + ((int)blue * (int)mlx->start_y);
		mlx->color = get_color(mlx);
	}
}
