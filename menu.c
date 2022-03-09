/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssulkuma <ssulkuma@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 15:37:12 by ssulkuma          #+#    #+#             */
/*   Updated: 2022/03/09 16:04:35 by ssulkuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	menu(t_mlx *mlx)
{
	int	color;

	color = 0x00FFFFFF;
	mlx_string_put(mlx->connection, mlx->window, 25, 20, mlx->top_color, "FDF");
	mlx_string_put(mlx->connection, mlx->window, 20, 40, color, "zoom: + / -");
	mlx_string_put(mlx->connection, mlx->window, 20, 60, color, "move: arrows");
	mlx_string_put(mlx->connection, mlx->window, 20, 80, color, "close: esc");
}
