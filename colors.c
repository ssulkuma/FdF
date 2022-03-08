/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssulkuma <ssulkuma@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 13:41:58 by ssulkuma          #+#    #+#             */
/*   Updated: 2022/03/08 14:57:25 by ssulkuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	check_color_arguments(t_mlx *mlx, char **argv)
{
	int	red;
	int	green;
	int	blue;

	if (argv[2] && argv[3] && argv[4])
	{
		red = ft_atoi(argv[2]);
		green = ft_atoi(argv[3]);
		blue = ft_atoi(argv[4]);
		if (red >= 0 && red <= 255 && green >= 0 && green <= 255
			&& blue >= 0 && blue <= 255)
		{
			mlx->color_r = red;
			mlx->color_g = green;
			mlx->color_b = blue;
		}
		else
			ft_putendl("Invalid colorvalues, using default colors.");
	}
}

int	get_color(t_mlx *mlx)
{
	return (mlx->color_t << 24 | mlx->color_r << 16 | mlx->color_g << 8
		| mlx->color_b);
}

static int	gradient(t_mlx *mlx, float step_x, float step_y)
{
	int		red;
	int		green;
	int		blue;
	float	steps;
	float	xy_position;

	if (step_x > step_y)
	{
		steps = mlx->end_x - mlx->start_x;
		xy_position = mlx->start_x;
	}
	else
	{
		steps = mlx->end_y - mlx->start_y;
		xy_position = mlx->start_y;
	}
	mlx->color = get_color(mlx);
	red = (255 - mlx->color_r) / steps;
	green = (255 - mlx->color_g) / steps;
	blue = (255 - mlx->color_b) / steps;
	printf("%s%d\n", "RED ", red);
	printf("%s%d\n", "GREEN ", green);
	printf("%s%d\n\n", "BLUE ", blue);
	red = (mlx->color >> 16 & 0xFF) + red * xy_position;
	green = (mlx->color >> 8 & 0xFF) + green * xy_position;
	blue = (mlx->color & 0xFF) + blue * xy_position;
	return (red << 16 | green << 8 | blue);
}

void	draw_color(t_mlx *mlx, float step_x, float step_y)
{
	if (mlx->start_z == 0 && mlx->end_z == 0)
		mlx->color = 0x00FFFFFF;
	else if (mlx->start_z != 0 && mlx->end_z != 0 && mlx->start_z == mlx->end_z)
		mlx->color = mlx->top_color;
	else
		mlx->color = gradient(mlx, step_x, step_y);
}
