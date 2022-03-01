/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_02.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssulkuma <ssulkuma@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 19:02:28 by ssulkuma          #+#    #+#             */
/*   Updated: 2022/03/01 12:50:58 by ssulkuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	add_zoom(t_mlx *mlx)
{
	mlx->start_x *= 30;
	mlx->start_y *= 30;
	mlx->end_x *= 30;
	mlx->end_y *= 30;
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
	mlx->start_x += 500;
	mlx->start_y -= 250;
	mlx->end_x += 500;
	mlx->end_y -= 250;
}
