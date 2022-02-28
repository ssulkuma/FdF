/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssulkuma <ssulkuma@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 15:12:35 by ssulkuma          #+#    #+#             */
/*   Updated: 2022/02/28 19:06:40 by ssulkuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "./minilibx/mlx.h"
# include "./libft/libft.h"

# include <stdio.h>
# include <fcntl.h>
# include <math.h>

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
	void	*image;
	char	*address;
	int		bits_per_pixel;
	int		line_len;
	int		endian;
	float	start_x;
	float	start_y;
	float	start_z;
	float	end_x;
	float	end_y;
	float	end_z;
}			t_mlx;

void	read_map(char *map_file, t_map *map);
void	error(const char *str);
void	check_valid_chars(char *line, int fd);
void	events(t_mlx *mlx);
void	draw(t_mlx *milx, t_map *map);
void	free_map(t_map *map);
void	zoom(t_mlx *mlx);

#endif
