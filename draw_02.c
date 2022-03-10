/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_02.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssulkuma <ssulkuma@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 19:02:28 by ssulkuma          #+#    #+#             */
/*   Updated: 2022/03/10 12:01:51 by ssulkuma         ###   ########.fr       */
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
	mlx->start_x = (mlx->start_x - mlx->start_y) * cos(1);
	mlx->start_y = (mlx->start_x + mlx->start_y) * sin(1) - mlx->start_z;
	mlx->end_x = (mlx->end_x - mlx->end_y) * cos(1);
	mlx->end_y = (mlx->end_x + mlx->end_y) * sin(1) - mlx->end_z;
}

void	pararell_projection(t_mlx *mlx)
{
	printf("%.5f\n", mlx->start_x);
}

void	center_position(t_mlx *mlx)
{
	mlx->start_x += mlx->position_x;
	mlx->start_y -= mlx->position_y;
	mlx->end_x += mlx->position_x;
	mlx->end_y -= mlx->position_y;
}
