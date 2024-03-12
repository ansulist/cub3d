/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_map2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ansulist <ansulist@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 07:13:08 by ansulist          #+#    #+#             */
/*   Updated: 2024/03/07 17:18:22 by ansulist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "libft/libft.h"

int	parse_map(int fd, t_cub3d *cub3d, int size_x, int size_y)
{
	cub3d->map.size_x = size_x;
	cub3d->map.size_y = size_y;
	cub3d->map.blocs = malloc(sizeof(char **) * (cub3d->map.size_y + 1));
	if (cub3d->map.blocs == NULL)
		return (-1);
	cub3d->map.bloc_px_size = 1;
	return (fill_map_blocs(fd, cub3d, size_x, 0));
}

char	**custom_split(char *line)
{
	char	**splitted;

	splitted = ft_split(line, ' ');
	if (splitted == NULL)
		return (NULL);
	if (splitted[0] != NULL
		&& splitted[1] != NULL
		&& ft_strlen(splitted[1]) >= 1
		&& splitted[1][ft_strlen(splitted[1]) - 1] == '\n')
		splitted[1][ft_strlen(splitted[1]) - 1] = '\0';
	return (splitted);
}

int	load_texture(char **splitted, char **texture)
{
	if (*texture != NULL)
		return (-1);
	*texture = ft_strdup(splitted[1]);
	return (0);
}
