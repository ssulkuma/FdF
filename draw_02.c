/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_02.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssulkuma <ssulkuma@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 19:02:28 by ssulkuma          #+#    #+#             */
/*   Updated: 2022/03/17 12:13:15 by ssulkuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	add_zoom(t_mlx *mlx)
{
	mlx->start_x *= mlx->zoom;
	mlx->start_y *= mlx->zoom;
	mlx->end_x *= mlx->zoom;
	mlx->end_y *= mlx->zoom;
	if (mlx->start_z == 0 && mlx->end_z == 0)
		;
	else
	{
		mlx->start_z *= mlx->altitude;
		mlx->end_z *= mlx->altitude;
	}
}

void	isometric_projection(t_mlx *mlx)
{
	mlx->start_x = (mlx->start_x - mlx->start_y) * cos(mlx->degree);
	mlx->start_y = (mlx->start_x + mlx->start_y) * sin(mlx->degree);
	mlx->start_y -= mlx->start_z;
	mlx->end_x = (mlx->end_x - mlx->end_y) * cos(mlx->degree);
	mlx->end_y = (mlx->end_x + mlx->end_y) * sin(mlx->degree);
	mlx->end_y -= mlx->end_z;
}

void	center_position(t_mlx *mlx)
{
	mlx->start_x += mlx->position_x;
	mlx->start_y -= mlx->position_y;
	mlx->end_x += mlx->position_x;
	mlx->end_y -= mlx->position_y;
}

float	get_max_delta(float step_x, float step_y)
{
	if (step_x < 0)
		step_x *= (-1);
	if (step_y < 0)
		step_y *= (-1);
	if (step_x > step_y)
		return (step_x);
	else
		return (step_y);
}
