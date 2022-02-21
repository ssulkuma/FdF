/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssulkuma <ssulkuma@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 16:15:37 by ssulkuma          #+#    #+#             */
/*   Updated: 2022/02/21 17:29:33 by ssulkuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	close_window(t_mlx *mlx, int keycode)
{
	t_map	map;

	if (keycode == 61)
	{
		while (map.cols >= 0)
			ft_memdel((void **)map.map[map.cols--]);
		ft_memdel((void **)map.map);
		mlx_destroy_window(mlx->connection, mlx->window);
		exit(0);
	}
	return (0);
}

void	events(t_mlx *mlx)
{
	mlx_key_hook(mlx->window, close_window, &mlx);
}
