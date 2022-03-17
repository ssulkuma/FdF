/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssulkuma <ssulkuma@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 16:15:37 by ssulkuma          #+#    #+#             */
/*   Updated: 2022/03/17 13:54:53 by ssulkuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	movement_keys(int keycode, t_mlx *mlx)
{
	if (keycode == PLUS_KEY)
		mlx->degree += 0.05;
	if (keycode == MINUS_KEY)
		mlx->degree -= 0.05;
	if (keycode == ARROW_LEFT)
		mlx->position_x -= 10;
	if (keycode == ARROW_RIGHT)
		mlx->position_x += 10;
	if (keycode == ARROW_DOWN)
		mlx->position_y -= 10;
	if (keycode == ARROW_UP)
		mlx->position_y += 10;
	mlx_destroy_image(mlx->connection, mlx->image);
	mlx_clear_window(mlx->connection, mlx->window);
	draw(mlx);
}

static void	projection_keys(int keycode, t_mlx *mlx)
{
	if (keycode == I_KEY)
	{
		mlx->degree = 1;
		mlx->position_x = 500;
		mlx->position_y = 250;
		mlx->projection = 1;
	}
	if (keycode == P_KEY)
	{
		mlx->position_x = 250;
		mlx->position_y = -100;
		mlx->projection = 2;
	}
	if (keycode == D_KEY)
			mlx->altitude -= 1;
	if (keycode == U_KEY)
		mlx->altitude += 1;
	mlx_destroy_image(mlx->connection, mlx->image);
	mlx_clear_window(mlx->connection, mlx->window);
	draw(mlx);
}

static int	key_events(int keycode, t_mlx *mlx)
{
	if (keycode == MINUS_KEY || keycode == PLUS_KEY
		|| keycode >= ARROW_LEFT || keycode <= ARROW_UP)
		movement_keys(keycode, mlx);
	if (keycode == I_KEY || keycode == P_KEY || keycode == D_KEY
		|| keycode == U_KEY)
		projection_keys(keycode, mlx);
	if (keycode == ESC_KEY)
	{
		mlx_destroy_image(mlx->connection, mlx->image);
		mlx_destroy_window(mlx->connection, mlx->window);
		free_map(mlx);
		exit (0);
	}
	return (0);
}

static int	mouse_events(int button, int x, int y, t_mlx *mlx)
{
	x = mlx->start_x;
	y = mlx->start_y;
	if (button == SCROLL_UP)
		mlx->zoom += 1;
	if (button == SCROLL_DOWN)
		mlx->zoom -= 1;
	mlx_destroy_image(mlx->connection, mlx->image);
	mlx_clear_window(mlx->connection, mlx->window);
	draw(mlx);
	return (0);
}

void	events(t_mlx *mlx)
{
	mlx_hook(mlx->window, 2, 0, key_events, mlx);
	mlx_hook(mlx->window, 4, 0, mouse_events, mlx);
}
