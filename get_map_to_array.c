/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_to_array.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ansulist <ansulist@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 20:57:45 by ansulist          #+#    #+#             */
/*   Updated: 2024/03/07 17:20:50 by ansulist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ignore_header(int fd)
{
	int		i;
	char	*line;

	i = 0;
	while (i < 6)
	{
		line = get_next_line(fd);
		if (line == NULL)
			return (-1);
		if (ft_strlen(line) > 1)
		{
			i++;
		}
	}
	return (0);
}

// Read lines from the map and ignore the line or count (x and y)
int	read_map_line_and_count(int fd, int *size_x, int *size_y)
{
	char	*line;
	int		i;

	line = get_next_line(fd);
	while (line != NULL)
	{
		if (ft_strcmp(line, "\n") != 0)
		{
			i = ft_strlen(line) - 1;
			if (i > *size_x)
				*size_x = i;
			(*size_y)++;
		}
		else if (*size_y > 0)
		{
			free(line);
			return (-1);
		}
		free(line);
		line = get_next_line(fd);
	}
	return (0);
}

// Get the map of the size looking at the configuration file
int	map_size_count(char *cubfile, int *size_x, int *size_y)
{
	int	ret;
	int	fd;

	fd = open_map(cubfile);
	if (fd == -1)
	{
		printf("Cannot open the map %s\n", cubfile);
		return (-1);
	}
	if (ignore_header(fd) == -1)
		return (-1);
	*size_x = 0;
	*size_y = 0;
	ret = read_map_line_and_count(fd, size_x, size_y);
	close(fd);
	return (ret);
}

int	check_empty(t_cub3d *cub3d)
{
	if (cub3d->map.blocs == NULL)
		return (-1);
	return (0);
}

int	check_validity(t_cub3d *cub3d)
{
	int	i;
	int	j;

	i = 0;
	while (cub3d->map.blocs[i] != NULL)
	{
		j = 0;
		while (cub3d->map.blocs[i][j] != '\0')
		{
			if (cub3d->map.blocs[i][j] != '0' &&
				cub3d->map.blocs[i][j] != ' ' &&
				cub3d->map.blocs[i][j] != '1' &&
				cub3d->map.blocs[i][j] != 'N' &&
				cub3d->map.blocs[i][j] != 'S' &&
				cub3d->map.blocs[i][j] != 'W' &&
				cub3d->map.blocs[i][j] != 'E')
				return (-1);
			j++;
		}
		i++;
	}
	return (0);
}
