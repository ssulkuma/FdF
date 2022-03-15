/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssulkuma <ssulkuma@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 15:37:12 by ssulkuma          #+#    #+#             */
/*   Updated: 2022/03/15 13:04:02 by ssulkuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	menu(t_mlx *mlx)
{
	int		color;
	void	*connection;
	void	*window;

	color = 0x00FFFFFF;
	connection = mlx->connection;
	window = mlx->window;
	mlx_string_put(connection, window, 25, 20, mlx->base_color, "FDF");
	mlx_string_put(connection, window, 20, 40, color, "zoom: scroll");
	mlx_string_put(connection, window, 20, 60, color, "move: arrows");
	mlx_string_put(connection, window, 20, 80, color, "altitude: U / D");
	mlx_string_put(connection, window, 20, 100, color, "projection: I / P");
	mlx_string_put(connection, window, 20, 120, color, "degree: + / -");
	mlx_string_put(connection, window, 20, 140, color, "close: esc");
}
