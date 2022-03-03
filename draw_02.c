/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_02.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssulkuma <ssulkuma@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 19:02:28 by ssulkuma          #+#    #+#             */
/*   Updated: 2022/03/03 16:59:17 by ssulkuma         ###   ########.fr       */
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

static int	get_color(t_mlx *mlx)
{
	return (mlx->color_t << 24 | mlx->color_r << 16 | mlx->color_g << 8
		| mlx->color_b);
}

void	draw_color(t_mlx *mlx)
{
	static int	color_shift;

	color_shift = 500;
	mlx->color = get_color(mlx);
	if (!mlx->start_z && !mlx->end_z)
		mlx->color = 0x00FFFFFF;
	if (mlx->start_z < mlx->end_z)
		mlx->color += color_shift;
	if (mlx->start_z > mlx->end_z)
		mlx->color -= color_shift;
}
