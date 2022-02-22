/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_02.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssulkuma <ssulkuma@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 19:00:32 by ssulkuma          #+#    #+#             */
/*   Updated: 2022/02/22 16:27:04 by ssulkuma         ###   ########.fr       */
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
	printf("%s%s\n", "LINE ", line);
	while (line[index] != '\0')
	{
		if (ft_isdigit(line[index]) || line[index] == ' ' || line[index] == '-')
		{
			if (line[index] == '-' && line[index + 1] == '-')
				invalid_map_error(line, fd);
			index++;
		}
		else
			invalid_map_error(line, fd);
	}
}
