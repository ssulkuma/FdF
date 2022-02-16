/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssulkuma <ssulkuma@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 16:51:12 by ssulkuma          #+#    #+#             */
/*   Updated: 2022/02/16 12:00:05 by ssulkuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	error(const char *str)
{
	perror(str);
	exit(1);
}

int	main(void)
{
	void	*connection;
	void	*window;

	connection = mlx_init();
	if (!connection)
		error("connection");
	window =  mlx_new_window(connection, 500, 500, "FdF");
	if (!window)
		error("window");
	mlx_loop(connection);
	return (0);
}
