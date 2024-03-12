/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_path_texture.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ansulist <ansulist@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 20:06:47 by ansulist          #+#    #+#             */
/*   Updated: 2024/03/07 16:43:08 by ansulist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	is_valid_path(char *path)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd < 0)
	{
		free(path);
		printf("Error: invalid texture path\n");
		return (-1);
	}
	return (0);
}

// Load one texture path from the file
char	*load_texture_path(int fd, char *id)
{
	char	*line;
	char	**splitted;

	line = get_next_line(fd);
	if (line == NULL)
		return (NULL);
	splitted = ft_split(line, ' ');
	free(line);
	if (splitted == NULL)
		return (NULL);
	if (splitted[0] == NULL || ft_strncmp(splitted[0], id, ft_strlen(id)) != 0)
	{
		ft_free_twod_array(splitted);
		return (NULL);
	}
	if (splitted[1] == NULL)
		return (NULL);
	line = ft_strdup(splitted[1]);
	line[ft_strlen(line) - 1] = '\0';
	ft_free_twod_array(splitted);
	return (line);
}

//  - 4 to remove .xpm from str the 4 + 1 to xpm thingy length
bool	check_path_extension(char *str)
{
	int	i;

	i = 0;
	i = (int)ft_strlen(str) - 4;
	if (i < 0 || ft_strncmp(".xpm", (str + i), 4 + 1))
		return (false);
	return (true);
}

bool	check_all_path_ext(t_cub3d *cub3d)
{
	if (is_valid_path(cub3d->textures.no) == -1)
		return (false);
	if (is_valid_path(cub3d->textures.so) == -1)
		return (false);
	if (is_valid_path(cub3d->textures.ea) == -1)
		return (false);
	if (is_valid_path(cub3d->textures.we) == -1)
		return (false);
	if (check_path_extension(cub3d->textures.no) == false)
		return (false);
	if (check_path_extension(cub3d->textures.so) == false)
		return (false);
	if (check_path_extension(cub3d->textures.ea) == false)
		return (false);
	if (check_path_extension(cub3d->textures.we) == false)
		return (false);
	return (true);
}
