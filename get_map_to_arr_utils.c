/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_to_arr_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ansulist <ansulist@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 16:16:18 by ansulist          #+#    #+#             */
/*   Updated: 2024/03/07 17:07:57 by ansulist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_walls_top_and_bottom(t_cub3d *cub3d)
{
	int	i;

	i = 0;
	while (cub3d->map.blocs[0][i] != ' ')
		i++;
	while (cub3d->map.blocs[0][i] != '\0')
	{
		if (cub3d->map.blocs[0][i] != '1' || cub3d->map.blocs[0][i] != ' ')
			return (-1);
		i++;
	}
	return (0);
}

int	check_sides_maps(t_cub3d *cub3d)
{
	if (check_sides_maps_horizontal(cub3d) == -1)
		return (-1);
	if (check_sides_maps_vertical(cub3d) == -1)
		return (-1);
	return (0);
}

// Check that every horizontal line starts with 
// a '1' and end with a '1' with the
// possibility of having space before
int	check_sides_maps_horizontal(t_cub3d *cub3d)
{
	int	i;
	int	j;

	i = 0;
	while (i < cub3d->map.size_y)
	{
		j = 0;
		while (cub3d->map.blocs[i][j] == ' ')
			j++;
		if (cub3d->map.blocs[i][j] != '1')
			return (-1);
		j = cub3d->map.size_x - 1;
		while (j >= 0 && cub3d->map.blocs[i][j] == ' ')
			j--;
		if (cub3d->map.blocs[i][j] != '1')
			return (-1);
		i++;
	}
	return (0);
}

// Check that every vertical line starts with a '1' and end with a '1' with the
// possibility of having space before
int	check_sides_maps_vertical(t_cub3d *cub3d)
{
	int	i;
	int	j;

	i = 0;
	while (i < cub3d->map.size_x)
	{
		j = 0;
		while (cub3d->map.blocs[j] != NULL && cub3d->map.blocs[j][i] == ' ')
			j++;
		if (cub3d->map.blocs[j] == NULL || cub3d->map.blocs[j][i] != '1')
			return (-1);
		j = cub3d->map.size_y - 1;
		while (cub3d->map.blocs[j] != NULL && cub3d->map.blocs[j][i] == ' ')
			j--;
		if (cub3d->map.blocs[j] == NULL || cub3d->map.blocs[j][i] != '1')
			return (-1);
		i++;
	}
	return (0);
}

int	check_space_neibours(t_cub3d *cub3d, int y, int x)
{
	if (y > 0 && (cub3d->map.blocs[y - 1][x] != '1'
		&& cub3d->map.blocs[y - 1][x] != ' '))
		return (-1);
	if (x > 0 && (cub3d->map.blocs[y][x - 1] != '1'
		&& cub3d->map.blocs[y][x - 1] != ' '))
		return (-1);
	if (cub3d->map.blocs[y][x + 1] != '\0'
		&& (cub3d->map.blocs[y][x + 1] != '1'
		&& cub3d->map.blocs[y][x + 1] != ' '))
		return (-1);
	if (cub3d->map.blocs[y + 1] != NULL
		&& (cub3d->map.blocs[y + 1][x] != '1'
		&& cub3d->map.blocs[y + 1][x] != ' '))
		return (-1);
	return (0);
}
