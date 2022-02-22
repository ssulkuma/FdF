/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssulkuma <ssulkuma@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 16:51:12 by ssulkuma          #+#    #+#             */
/*   Updated: 2022/02/22 16:26:10 by ssulkuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	error(const char *str)
{
	perror(str);
	exit(1);
}

int	main(int argc, char **argv)
{
	t_mlx	mlx;
	t_map	map;

	if (argc != 2)
	{
		ft_putendl("Usage: ./fdf [map_file]");
		return (1);
	}
	read_map(argv[1], &map);
	mlx.connection = mlx_init();
	if (!mlx.connection)
		error("error");
	mlx.window = mlx_new_window(mlx.connection, 500, 500, "FdF");
	if (!mlx.window)
		error("error");
	printf("%d\n", map.cols);
	events(&mlx, &map);
	mlx_loop(mlx.connection);
	return (0);
}
