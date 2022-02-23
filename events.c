/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssulkuma <ssulkuma@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 16:15:37 by ssulkuma          #+#    #+#             */
/*   Updated: 2022/02/22 18:53:01 by ssulkuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	close_window(t_mlx *mlx)
{

	//if (keycode == 61)
	//{
		while (mlx->map.cols >= 0)
		{
			ft_memdel((void **)mlx->map.map[mlx->map.cols]);
			mlx->map.cols--;
		}
		ft_memdel((void **)mlx->map.map);
		mlx_destroy_window(mlx->connection, mlx->window);
		exit(0);
	//}
	//return (0);
}

void	events(t_mlx *mlx)
{
	printf("%d\n", mlx->map.cols);
	mlx_key_hook(mlx->window, close_window, &mlx);
}
