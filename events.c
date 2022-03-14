/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssulkuma <ssulkuma@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 16:15:37 by ssulkuma          #+#    #+#             */
/*   Updated: 2022/03/14 11:52:10 by ssulkuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	movement_keys(int keycode, t_mlx *mlx)
{
	if (keycode == 27)
		mlx->zoom += 1;
	if (keycode == 44)
		mlx->zoom -= 1;
	if (keycode == 123)
		mlx->position_x -= 10;
	if (keycode == 124)
		mlx->position_x += 10;
	if (keycode == 125)
		mlx->position_y -= 10;
	if (keycode == 126)
		mlx->position_y += 10;
	if (keycode == 18)
		mlx->degree += 0.05;
	if (keycode == 19)
		mlx->degree -= 0.05;
	mlx_destroy_image(mlx->connection, mlx->image);
	mlx_clear_window(mlx->connection, mlx->window);
	draw(mlx);
}

static void	projection_keys(int keycode, t_mlx *mlx)
{
	if (keycode == 34)
	{
		mlx->position_x = 500;
		mlx->position_y = 250;
		mlx->projection = 1;
	}
	if (keycode == 35)
	{
		mlx->position_x = 250;
		mlx->position_y = -100;
		mlx->projection = 2;
	}
	mlx_destroy_image(mlx->connection, mlx->image);
	mlx_clear_window(mlx->connection, mlx->window);
	draw(mlx);
}

static int	key_events(int keycode, t_mlx *mlx)
{
	if (keycode == 27 || keycode == 44 || keycode >= 123 || keycode <= 126)
		movement_keys(keycode, mlx);
	if (keycode == 34 || keycode == 35)
		projection_keys(keycode, mlx);
	if (keycode == 2 || keycode == 32)
	{
		if (keycode == 2)
			mlx->altitude -= 1;
		else
			mlx->altitude += 1;
		mlx_destroy_image(mlx->connection, mlx->image);
		mlx_clear_window(mlx->connection, mlx->window);
		draw(mlx);
	}
	if (keycode == 53)
	{
		mlx_destroy_image(mlx->connection, mlx->image);
		mlx_destroy_window(mlx->connection, mlx->window);
		free_map(mlx);
		exit (0);
	}
	return (0);
}

void	events(t_mlx *mlx)
{
	mlx_hook(mlx->window, 2, 0, key_events, mlx);
}
