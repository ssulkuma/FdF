/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssulkuma <ssulkuma@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 16:15:37 by ssulkuma          #+#    #+#             */
/*   Updated: 2022/03/01 18:02:57 by ssulkuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	key_events(int keycode, t_mlx *mlx)
{
	if (keycode == 27 || keycode == 44)
	{
		if (keycode == 27)
			mlx->zoom += 1;
		if (keycode == 44)
			mlx->zoom -= 1;
		mlx_destroy_image(mlx->connection, mlx->image);
		mlx_clear_window(mlx->connection, mlx->window);
		draw(mlx);
	}
	if (keycode == 53)
	{
		free_map(mlx);
		mlx_destroy_image(mlx->connection, mlx->image);
		mlx_destroy_window(mlx->connection, mlx->window);
		exit (0);
	}
	return (0);
}

void	events(t_mlx *mlx)
{
	mlx_hook(mlx->window, 2, 0, key_events, &mlx);
}
