/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ansulist <ansulist@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 16:33:36 by ansulist          #+#    #+#             */
/*   Updated: 2024/03/07 17:40:04 by ansulist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_direction_for_player(t_cub3d *cub3d)
{
	if (cub3d->player_position == 'N')
	{
		cub3d->player.dir.x = 0;
		cub3d->player.dir.y = -1;
	}
	if (cub3d->player_position == 'S')
	{
		cub3d->player.dir.x = 0;
		cub3d->player.dir.y = 1;
	}
	if (cub3d->player_position == 'E')
	{
		cub3d->player.dir.x = 1;
		cub3d->player.dir.y = 0;
	}
	if (cub3d->player_position == 'W')
	{
		cub3d->player.dir.x = -1;
		cub3d->player.dir.y = 0;
	}
}

void	check_plane_for_player(t_cub3d *cub3d)
{
	if (cub3d->player_position == 'N')
	{
		cub3d->player.plane.x = 0.66;
		cub3d->player.plane.y = 0;
	}
	if (cub3d->player_position == 'S')
	{
		cub3d->player.plane.x = -0.66;
		cub3d->player.plane.y = 0;
	}
	if (cub3d->player_position == 'E')
	{
		cub3d->player.plane.x = 0;
		cub3d->player.plane.y = 0.66;
	}
	if (cub3d->player_position == 'W')
	{
		cub3d->player.plane.x = 0;
		cub3d->player.plane.y = -0.66;
	}
}

void	init_cub3d(t_cub3d *cub3d)
{
	cub3d->map.size_x = 0;
	cub3d->map.size_y = 0;
	cub3d->map.bloc_px_size = 1;
	cub3d->player.angle = deg_to_rad(0);
	cub3d->player.pos.x = 5;
	cub3d->player.pos.y = 5;
	cub3d->player.dir.x = -1;
	cub3d->player.dir.y = 0;
	cub3d->player.plane.x = 0;
	cub3d->player.plane.y = -0.66;
	cub3d->textures.no = NULL;
	cub3d->textures.so = NULL;
	cub3d->textures.we = NULL;
	cub3d->textures.ea = NULL;
}

void	init_image(t_cub3d *cub3d)
{
	cub3d->image.img = mlx_new_image(cub3d->mlx, WINDOW_SIZE_X, WINDOW_SIZE_Y);
	cub3d->image.address = mlx_get_data_addr(cub3d->image.img,
			&cub3d->image.bits_per_pixel,
			&cub3d->image.size_line, &cub3d->image.endian);
}

int	check_ac_av(int ac, char **av)
{
	(void) av;
	if (ac != 2)
	{
		printf("ehhhh wrongg input dude\n\n");
		return (-1);
	}
	return (0);
}
