/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_moves.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ansulist <ansulist@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 15:37:57 by ansulist          #+#    #+#             */
/*   Updated: 2024/03/07 17:39:32 by ansulist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

float	deg_to_rad(float a)
{
	return (a * (PI / 180.0));
}

void	keyw_handler(t_cub3d *cub3d)
{
	t_point	pos;

	pos.x = cub3d->player.pos.x + cub3d->player.dir.x * 0.1;
	pos.y = cub3d->player.pos.y + cub3d->player.dir.y * 0.1;
	if (cub3d->map.blocs[(int)cub3d->player.pos.y][(int)pos.x] != '1')
		cub3d->player.pos.x = pos.x;
	if (cub3d->map.blocs[(int)pos.y][(int)cub3d->player.pos.x] != '1')
		cub3d->player.pos.y = pos.y;
}

// down
void	keys_handler(t_cub3d *cub3d)
{
	t_point	pos;

	pos.x = cub3d->player.pos.x - cub3d->player.dir.x * 0.1;
	pos.y = cub3d->player.pos.y - cub3d->player.dir.y * 0.1;
	if (cub3d->map.blocs[(int)cub3d->player.pos.y][(int)pos.x] != '1')
		cub3d->player.pos.x = pos.x;
	if (cub3d->map.blocs[(int)pos.y][(int)cub3d->player.pos.x] != '1')
		cub3d->player.pos.y = pos.y;
}

// right
void	keyd_handler(t_cub3d *cub3d)
{
	t_point	pos;
	t_point	dir;
	float	a;

	a = deg_to_rad(90);
	dir.x = cub3d->player.dir.x * cos(1 * a)
		+ cub3d->player.dir.y * -sin(1 * a);
	dir.y = cub3d->player.dir.x * sin(1 * a) + cub3d->player.dir.y * cos(1 * a);
	pos.x = cub3d->player.pos.x + dir.x * 0.1;
	pos.y = cub3d->player.pos.y + dir.y * 0.1;
	if (cub3d->map.blocs[(int)cub3d->player.pos.y][(int)pos.x] != '1')
		cub3d->player.pos.x = pos.x;
	if (cub3d->map.blocs[(int)pos.y][(int)cub3d->player.pos.x] != '1')
		cub3d->player.pos.y = pos.y;
}

// left
void	keya_handler(t_cub3d *cub3d)
{
	t_point	pos;
	t_point	dir;
	float	a;

	a = deg_to_rad(90);
	dir.x = cub3d->player.dir.x * cos(-1 * a)
		+ cub3d->player.dir.y * -sin(-1 * a);
	dir.y = cub3d->player.dir.x * sin(-1 * a)
		+ cub3d->player.dir.y * cos(-1 * a);
	pos.x = cub3d->player.pos.x + dir.x * 0.1;
	pos.y = cub3d->player.pos.y + dir.y * 0.1;
	if (cub3d->map.blocs[(int)cub3d->player.pos.y][(int)pos.x] != '1')
		cub3d->player.pos.x = pos.x;
	if (cub3d->map.blocs[(int)pos.y][(int)cub3d->player.pos.x] != '1')
		cub3d->player.pos.y = pos.y;
}
