/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssulkuma <ssulkuma@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 16:51:12 by ssulkuma          #+#    #+#             */
/*   Updated: 2022/02/17 17:02:10 by ssulkuma         ###   ########.fr       */
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
	int		rd_value;

	if (argc != 2)
	{
		ft_putendl("Usage: ./fdf [map_file]");
		return (1);
	}
	rd_value = read_map(argv[1]);
	if (rd_value == -1)
		error("read");
	connection = mlx_init();
	if (!connection)
		error("connection");
	window =  mlx_new_window(connection, 500, 500, "FdF");
	if (!window)
		error("window");
	mlx_loop(connection);
	return (0);
}
