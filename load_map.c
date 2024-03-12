/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ansulist <ansulist@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 20:04:42 by ansulist          #+#    #+#             */
/*   Updated: 2024/03/07 16:46:45 by ansulist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// Make the line to be at least of the given size
// Fill the blank with provided character
int	fill_line(char **line, int size, char c)
{
	int		len;
	char	*filled_line;
	int		i;

	len = ft_strlen(*line);
	if (len >= size)
		return (0);
	filled_line = malloc(size + 1);
	if (filled_line == NULL)
		return (-1);
	i = 0;
	while (i < len)
	{
		filled_line[i] = (*line)[i];
		i++;
	}
	while (i < size)
	{
		filled_line[i] = c;
		i++;
	}
	filled_line[i] = '\0';
	*line = filled_line;
	return (0);
}

int	fill_map_blocs(int fd, t_cub3d *cub3d, int size_x, int i)
{
	char	*line;

	line = get_next_line(fd);
	while (line != NULL)
	{
		if (ft_strcmp(line, "\n") != 0)
		{
			if (ft_strlen(line) > 0)
				line[ft_strlen(line) - 1] = '\0';
			if (fill_line(&line, size_x, ' ') == -1)
			{
				free(line);
				ft_free_twod_array(cub3d->map.blocs);
				return (-1);
			}
			cub3d->map.blocs[i] = line;
			i++;
		}
		else
			free(line);
		line = get_next_line(fd);
	}
	cub3d->map.blocs[i] = NULL;
	return (0);
}

int	parse_header_line(t_cub3d *cub3d, char **spl, bool *f_color, bool *c_color)
{
	if (ft_strcmp(spl[0], "NO") == 0)
		return (load_texture(spl, &cub3d->textures.no));
	if (ft_strcmp(spl[0], "SO") == 0)
		return (load_texture(spl, &cub3d->textures.so));
	if (ft_strcmp(spl[0], "WE") == 0)
		return (load_texture(spl, &cub3d->textures.we));
	if (ft_strcmp(spl[0], "EA") == 0)
		return (load_texture(spl, &cub3d->textures.ea));
	if (ft_strcmp(spl[0], "F") == 0)
	{
		if (*f_color == true || parse_rgb_color(spl[1], &cub3d->color_f) == -1)
			return (-1);
		*f_color = true;
		return (0);
	}
	if (ft_strcmp(spl[0], "C") == 0)
	{
		if (*c_color == true || parse_rgb_color(spl[1], &cub3d->color_c) == -1)
			return (-1);
		*c_color = true;
		return (0);
	}
	if (spl[0] != NULL && ft_strcmp(spl[0], "\n") == 0 && spl[1] == NULL)
		return (0);
	return (-1);
}

int	parse_header(int fd, t_cub3d *cub3d, int ret)
{
	bool	f_color;
	bool	c_color;
	char	*line;
	char	**splitted;

	f_color = false;
	c_color = false;
	while ((cub3d->textures.no == NULL || cub3d->textures.so == NULL
			|| cub3d->textures.we == NULL || cub3d->textures.ea == NULL
			|| !f_color || !c_color) && ret != -1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			return (-1);
		splitted = custom_split(line);
		free(line);
		if (splitted == NULL)
			return (-1);
		if (parse_header_line(cub3d, splitted, &f_color, &c_color) == -1)
			ret = -1;
		ft_free_twod_array(splitted);
	}
	return (ret);
}

// Mutate cub3d with all necessary informations coming from the
// configuration file (textures, map, player position and colors)
int	load_config_from_file(char *cubfile, t_cub3d *cub3d)
{
	int	fd;
	int	ret;
	int	size_x;
	int	size_y;

	if (map_size_count(cubfile, &size_x, &size_y) == -1)
		return (-1);
	fd = open_map(cubfile);
	if (fd == -1)
		return (-1);
	ret = parse_header(fd, cub3d, 0);
	if (ret == -1)
	{
		close(fd);
		return (-1);
	}
	ret = parse_map(fd, cub3d, size_x, size_y);
	close(fd);
	if (ret == -1)
		return (-1);
	return (check_map_full(cub3d));
}
