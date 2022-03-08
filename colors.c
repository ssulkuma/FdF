/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssulkuma <ssulkuma@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 13:41:58 by ssulkuma          #+#    #+#             */
/*   Updated: 2022/03/08 16:56:44 by ssulkuma         ###   ########.fr       */
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

static int	gradient(t_mlx *mlx, float color_step)
{
	int		red;
	int		green;
	int		blue;

	printf("%s%.5f\n", "COLOR STEPS ", color_step);
	red = (255 - (mlx->top_color >> 16)) / color_step;
	green = (255 - (mlx->top_color >> 8 & 0xFF)) / color_step;
	blue = (255 - (mlx->top_color & 0xFF)) / color_step;
	printf("%s%d\n", "RED ", red);
	printf("%s%d\n", "GREEN ", green);
	printf("%s%d\n\n", "BLUE ", blue);
	if (mlx->start_z > mlx->end_z)
	{
		mlx->color_r = (mlx->color >> 16 & 0xFF) + red;
		mlx->color_g = (mlx->color >> 8 & 0xFF) + green;
		mlx->color_b = (mlx->color & 0xFF) + blue;
	}
	else
	{
		mlx->color_r = (mlx->color >> 16 & 0xFF) - red;
		mlx->color_g = (mlx->color >> 8 & 0xFF) - green;
		mlx->color_b = (mlx->color & 0xFF) - blue;
	}
	mlx->color = get_color(mlx);
	return (mlx->color);
}

void	draw_color(t_mlx *mlx, float color_step)
{
	if (mlx->start_z == 0 && mlx->end_z == 0)
		mlx->color = 0x00FFFFFF;
	else if (mlx->start_z != 0 && mlx->end_z != 0 && mlx->start_z == mlx->end_z)
		mlx->color = mlx->top_color;
	else
		mlx->color = gradient(mlx, color_step);
}
