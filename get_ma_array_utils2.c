/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_ma_array_utils2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ansulist <ansulist@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 16:19:05 by ansulist          #+#    #+#             */
/*   Updated: 2024/03/07 17:21:29 by ansulist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_inside_map(t_cub3d *cub3d)
{
	int	y;
	int	x;

	y = 0;
	while (y < cub3d->map.size_y)
	{
		x = 0;
		while (x < cub3d->map.size_x)
		{
			if (cub3d->map.blocs[y][x] == ' ')
			{
				if (check_space_neibours(cub3d, y, x) == -1)
					return (-1);
			}
			x++;
		}
		y++;
	}
	return (0);
}

int	check_player_direction(t_cub3d *cub3d, int x, int y, int player_pos)
{
	while (y < cub3d->map.size_y)
	{
		x = 0;
		while (x < cub3d->map.size_x)
		{
			if (cub3d->map.blocs[y][x] == 'N' ||
				cub3d->map.blocs[y][x] == 'S' ||
				cub3d->map.blocs[y][x] == 'W' ||
				cub3d->map.blocs[y][x] == 'E')
			{
				player_pos++;
				cub3d->player_position = cub3d->map.blocs[y][x];
				cub3d->player.pos.x = x;
				cub3d->player.pos.y = y;
				if (player_pos > 1)
					return (-1);
			}
			x++;
		}
		y++;
	}
	if (player_pos == 0)
		return (-1);
	return (0);
}

int	check_map_full(t_cub3d *cub3d)
{
	if (check_empty(cub3d) == -1)
	{
		printf("Error map is empty\n");
		return (-1);
	}
	if (check_validity(cub3d) == -1)
	{
		printf("Error map is invalid\n");
		return (-1);
	}
	if (check_sides_maps(cub3d) == -1)
	{
		printf("Error map sides are wrong\n");
		return (-1);
	}
	if (check_map_more(cub3d) == -1)
		return (-1);
	return (0);
}

int	check_map_more(t_cub3d *cub3d)

{
	if (check_inside_map(cub3d) == -1)
	{
		printf("Error inside of the map is wrong\n");
		return (-1);
	}
	if (check_player_direction(cub3d, 0, 0, 0) == -1)
	{
		printf("Error with player direction\n");
		return (-1);
	}
	if (check_all_path_ext(cub3d) == false)
	{
		printf("Error with texture path\n");
		return (-1);
	}
	return (0);
}
