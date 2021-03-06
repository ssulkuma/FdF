/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_02.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssulkuma <ssulkuma@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 19:00:32 by ssulkuma          #+#    #+#             */
/*   Updated: 2022/03/15 15:54:13 by ssulkuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	invalid_map_error(char *line, int fd)
{
	free(line);
	close(fd);
	ft_putendl("error: invalid map");
	exit(1);
}

void	check_valid_chars(char *line, int fd)
{
	int	index;

	index = 0;
	while (line[index] != '\0')
	{
		if (ft_isalnum(line[index]) || line[index] == ' ' || line[index] == '-'
			|| line[index] == ',')
		{
			if (line[index] == '-' && !ft_isalnum(line[index + 1]))
				invalid_map_error(line, fd);
			if (line[index] == ',' && !ft_isalnum(line[index + 1]))
				invalid_map_error(line, fd);
			index++;
		}
		else
			invalid_map_error(line, fd);
	}
}
