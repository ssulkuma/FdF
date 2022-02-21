/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssulkuma <ssulkuma@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 16:51:12 by ssulkuma          #+#    #+#             */
/*   Updated: 2022/02/21 17:28:50 by ssulkuma         ###   ########.fr       */
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
	int		rd_value;

	if (argc != 2)
	{
		ft_putendl("Usage: ./fdf [map_file]");
		return (1);
	}
	rd_value = read_map(argv[1]);
	if (rd_value == -1)
		error("error");
	mlx.connection = mlx_init();
	if (!mlx.connection)
		error("error");
	mlx.window = mlx_new_window(mlx.connection, 500, 500, "FdF");
	if (!mlx.window)
		error("error");
	events(&mlx);
	mlx_loop(mlx.connection);
	return (0);
}
