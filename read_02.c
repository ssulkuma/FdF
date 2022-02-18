/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_02.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssulkuma <ssulkuma@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 19:00:32 by ssulkuma          #+#    #+#             */
/*   Updated: 2022/02/18 19:52:02 by ssulkuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	check_valid_chars(char *line, int fd)
{
	int	index;

	index = 0;
	while (line[index] != '\0')
	{
		if (ft_isdigit(line[index]) || line[index] == ' ' || line[index] == '-')
			index++;
		else
		{
			close(fd);
			ft_putendl("error: invalid map");
			exit(1);
		}
	}
}
