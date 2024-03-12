/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_map_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ansulist <ansulist@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 20:04:18 by ansulist          #+#    #+#             */
/*   Updated: 2024/03/07 17:01:06 by ansulist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	open_map(char *av)
{
	int	fd;

	fd = open(av, O_RDONLY);
	if (fd == -1)
		printf("Map cannot be opened, check again\n");
	return (fd);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s2[i] != '\0' && s1[i] == s2[i])
	{
		i++;
	}
	return (s1[i] - s2[i]);
}

int	ft_free_twod_array(char **str)
{
	int	i;

	i = 0;
	if (str == NULL)
		return (-1);
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
	return (0);
}

int	free_path_texture(t_cub3d *cub3d)
{
	if (cub3d->textures.no != NULL)
		free(cub3d->textures.no);
	if (cub3d->textures.so != NULL)
		free(cub3d->textures.so);
	if (cub3d->textures.ea != NULL)
		free(cub3d->textures.ea);
	if (cub3d->textures.we != NULL)
		free(cub3d->textures.we);
	return (0);
}
