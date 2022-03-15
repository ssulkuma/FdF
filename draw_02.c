/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_02.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssulkuma <ssulkuma@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 19:02:28 by ssulkuma          #+#    #+#             */
/*   Updated: 2022/03/15 15:41:48 by ssulkuma         ###   ########.fr       */
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
	else if (mlx->start_z == mlx->end_z && mlx->start_z != 0 && mlx->end_z != 0)
	{
		mlx->start_z += mlx->altitude;
		mlx->end_z += mlx->altitude;
	}
	else if (mlx->start_z < mlx->end_z)
		mlx->end_z += mlx->altitude;
	else
		mlx->start_z += mlx->altitude;
}

void	isometric_projection(t_mlx *mlx)
{
	mlx->start_x = (mlx->start_x - mlx->start_y) * cos(mlx->degree);
	mlx->start_y = (mlx->start_x + mlx->start_y) * sin(mlx->degree) - mlx->start_z;
	mlx->end_x = (mlx->end_x - mlx->end_y) * cos(mlx->degree);
	mlx->end_y = (mlx->end_x + mlx->end_y) * sin(mlx->degree) - mlx->end_z;
}

void	center_position(t_mlx *mlx)
{
	mlx->start_x += mlx->position_x;
	mlx->start_y -= mlx->position_y;
	mlx->end_x += mlx->position_x;
	mlx->end_y -= mlx->position_y;
}
