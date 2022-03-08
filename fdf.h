/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssulkuma <ssulkuma@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 15:12:35 by ssulkuma          #+#    #+#             */
/*   Updated: 2022/03/08 20:03:42 by ssulkuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "./minilibx/mlx.h"
# include "./libft/libft.h"

# include <stdio.h>
# include <fcntl.h>
# include <math.h>

typedef struct s_mlx
{
	void	*connection;
	void	*window;
	void	*image;
	char	*address;
	int		rows;
	int		cols;
	int		**map;
	int		bits_per_pixel;
	int		line_len;
	int		endian;
	int		color;
	int		zoom;
	int		position_x;
	int		position_y;
	int		color_t;
	int		color_r;
	int		color_g;
	int		color_b;
	int		top_color;
	float	start_x;
	float	start_y;
	float	start_z;
	float	end_x;
	float	end_y;
	float	end_z;
}			t_mlx;

void	read_map(char *map_file, t_mlx *mlx);
void	error(const char *str);
void	check_valid_chars(char *line, int fd);
void	events(t_mlx *mlx);
void	draw(t_mlx *mlx);
void	free_map(t_mlx *mlx);
void	add_zoom(t_mlx *mlx);
void	isometric_projection(t_mlx *mlx);
void	center_position(t_mlx *mlx);
void	draw_color(t_mlx *mlx, float max_delta, int color_add);
void	check_color_arguments(t_mlx *mlx, char **argv);
int		get_color(t_mlx *mlx);

#endif
