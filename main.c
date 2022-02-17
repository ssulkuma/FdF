/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssulkuma <ssulkuma@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 16:51:12 by ssulkuma          #+#    #+#             */
/*   Updated: 2022/02/17 13:21:51 by ssulkuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	error(const char *str)
{
	perror(str);
	exit(1);
}

int	main(int argc, char **argv)
{
	void	*connection;
	void	*window;

	if (argc != 2)
		ft_putendl("Usage: ./fdf [map_file]");
	read_map(argv[1]);
	connection = mlx_init();
	if (!connection)
		error("connection");
	window =  mlx_new_window(connection, 500, 500, "FdF");
	if (!window)
		error("window");
	mlx_loop(connection);
	return (0);
}
