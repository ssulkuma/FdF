/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssulkuma <ssulkuma@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 13:41:58 by ssulkuma          #+#    #+#             */
/*   Updated: 2022/03/15 15:16:33 by ssulkuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	check_if_digits(char **argv)
{
	int	index;

	index = 0;
	while (argv[2][index] != '\0')
	{
		if (!ft_isdigit(argv[2][index]))
			return (0);
		index++;
	}
	index = 0;
	while (argv[3][index] != '\0')
	{
		if (!ft_isdigit(argv[3][index]))
			return (0);
		index++;
	}
	index = 0;
	while (argv[4][index] != '\0')
	{
		if (!ft_isdigit(argv[4][index]))
			return (0);
		index++;
	}
	return (1);
}

void	check_color_arguments(t_mlx *mlx, char **argv)
{
	int	red;
	int	green;
	int	blue;

	if (argv[2] && argv[3] && argv[4])
	{
		if (!check_if_digits(argv))
		{
			ft_putendl("Invalid colorvalues, using default colors.");
			return ;
		}
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

static int	gradient(t_mlx *mlx, float max_delta, int color_add)
{
	int		red;
	int		green;
	int		blue;

	red = (255 - (mlx->base_color >> 16 & 0xFF)) / max_delta;
	green = (255 - (mlx->base_color >> 8 & 0xFF)) / max_delta;
	blue = (255 - (mlx->base_color & 0xFF)) / max_delta;
	if ((mlx->start_z > mlx->end_z && mlx->start_z >= 0 && mlx->end_z >= 0)
		|| (mlx->start_z < mlx->end_z && mlx->start_z <= 0 && mlx->end_z <= 0))
	{
		mlx->color_r = (mlx->base_color >> 16 & 0xFF) + (red * color_add);
		mlx->color_g = (mlx->base_color >> 8 & 0xFF) + (green * color_add);
		mlx->color_b = (mlx->base_color & 0xFF) + (blue * color_add);
	}
	else
	{
		mlx->color_r = 255 - (red * color_add);
		mlx->color_g = 255 - (green * color_add);
		mlx->color_b = 255 - (blue * color_add);
	}
	mlx->color = get_color(mlx);
	return (mlx->color);
}

void	draw_color(t_mlx *mlx, float max_delta, int color_add)
{
	if (mlx->start_z == 0 && mlx->end_z == 0)
		mlx->color = 0x00FFFFFF;
	else if (mlx->start_z != 0 && mlx->end_z != 0 && mlx->start_z == mlx->end_z)
		mlx->color = mlx->base_color;
	else
		mlx->color = gradient(mlx, max_delta, color_add);
}
