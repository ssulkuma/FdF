/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssulkuma <ssulkuma@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 19:05:50 by ssulkuma          #+#    #+#             */
/*   Updated: 2022/02/23 18:20:59 by ssulkuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	draw_pixel_to_image(t_mlx *mlx, int x, int y, int color)
{
	char	*dest;

	dest = mlx->address + (y * mlx->line_len + x * (mlx->bits_per_pixel / 8));
	*(unsigned int *)dest = color;
}

void	draw(t_mlx *mlx)
{
	mlx->image = mlx_new_image(mlx->connection, 500, 500);
	mlx->address = mlx_get_data_addr(mlx->image, &mlx->bits_per_pixel,
			&mlx->line_len, &mlx->endian);
	draw_pixel_to_image(mlx, 10, 10, 0x00FF0000);
	mlx_put_image_to_window(mlx->connection, mlx->window, mlx->image, 0, 0);
}
