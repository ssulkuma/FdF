/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssulkuma <ssulkuma@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 15:12:35 by ssulkuma          #+#    #+#             */
/*   Updated: 2022/03/15 13:04:58 by ssulkuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "./minilibx/mlx.h"
# include "./libft/libft.h"

# include <stdio.h>
# include <fcntl.h>
# include <math.h>

# define MAX_ALTITUDE 10000
# define MIN_ALTITUDE -10000
# define ESC_KEY 53
# define ARROW_LEFT 123
# define ARROW_RIGHT 124
# define ARROW_DOWN 125
# define ARROW_UP 126
# define PLUS_KEY 24
# define MINUS_KEY 27
# define U_KEY 32
# define D_KEY 2
# define I_KEY 34
# define P_KEY 35
# define SCROLL_UP 4
# define SCROLL_DOWN 5

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
	int		altitude;
	int		color_t;
	int		color_r;
	int		color_g;
	int		color_b;
	int		base_color;
	int		projection;
	float	degree;
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
void	menu(t_mlx *mlx);
void	draw_color(t_mlx *mlx, float max_delta, int color_add);
void	check_color_arguments(t_mlx *mlx, char **argv);
int		get_color(t_mlx *mlx);

#endif
