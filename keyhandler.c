/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhandler.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ansulist <ansulist@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 07:09:31 by ansulist          #+#    #+#             */
/*   Updated: 2024/03/07 17:18:47 by ansulist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	keyleft_handler(t_cub3d *cub3d)
{
	t_point	plane;
	t_point	dir;

	plane.x = cub3d->player.plane.x * cos(-1 * 0.03)
		+ cub3d->player.plane.y * -sin(-1 * 0.03);
	plane.y = cub3d->player.plane.x * sin(-1 * 0.03)
		+ cub3d->player.plane.y * cos(-1 * 0.03);
	dir.x = cub3d->player.dir.x * cos(-1 * 0.03)
		+ cub3d->player.dir.y * -sin(-1 * 0.03);
	dir.y = cub3d->player.dir.x * sin(-1 * 0.03)
		+ cub3d->player.dir.y * cos(-1 * 0.03);
	cub3d->player.dir = dir;
	cub3d->player.plane = plane;
}

void	keyright_handler(t_cub3d *cub3d)
{
	t_point	plane;
	t_point	dir;

	plane.x = cub3d->player.plane.x * cos(1 * 0.03)
		+ cub3d->player.plane.y * -sin(1 * 0.03);
	plane.y = cub3d->player.plane.x * sin(1 * 0.03)
		+ cub3d->player.plane.y * cos(1 * 0.03);
	dir.x = cub3d->player.dir.x * cos(1 * 0.03)
		+ cub3d->player.dir.y * -sin(1 * 0.03);
	dir.y = cub3d->player.dir.x * sin(1 * 0.03)
		+ cub3d->player.dir.y * cos(1 * 0.03);
	cub3d->player.dir = dir;
	cub3d->player.plane = plane;
}
