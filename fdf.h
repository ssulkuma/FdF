/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssulkuma <ssulkuma@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 15:12:35 by ssulkuma          #+#    #+#             */
/*   Updated: 2022/02/18 11:26:43 by ssulkuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "./minilibx/mlx.h"
# include "./libft/libft.h"

# include <stdio.h>
# include <fcntl.h>

typedef struct s_map
{
	int		rows;
	int		cols;
	int		**map;
}			t_map;

typedef struct s_mlx
{
	void	*connection;
	void	*window;
	float	x;
	float	y;
	float	z;
}			t_mlx;

int	read_map(char *map_file);

#endif
