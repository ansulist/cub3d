/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_calculation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ansulist <ansulist@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 07:16:01 by ansulist          #+#    #+#             */
/*   Updated: 2024/03/07 16:28:45 by ansulist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_point	calculate_ray_direction(t_cub3d *cub3d, float camera_x)
{
	t_point	ray_direction;

	ray_direction.x = cub3d->player.dir.x + cub3d->player.plane.x * camera_x;
	ray_direction.y = cub3d->player.dir.y + cub3d->player.plane.y * camera_x;
	return (ray_direction);
}

// length of ray from one x or y-side to next x or y-side
t_point	calculate_delta_distance(t_point *ray_direction)
{
	t_point	delta_dist;

	delta_dist.x = fabs(1. / ray_direction->x);
	delta_dist.y = fabs(1. / ray_direction->y);
	return (delta_dist);
}

t_point	calculate_step(t_point *ray_direction)
{
	t_point	step;

	if (ray_direction->x < 0)
		step.x = -1;
	else
		step.x = 1;
	if (ray_direction->y < 0)
		step.y = -1;
	else
		step.y = 1;
	return (step);
}

t_point	calcsid(t_cub3d *cub3d, t_point *rayd, t_point *map, t_point *deltd)
{
	t_point	side_dist;

	if (rayd->x < 0)
		side_dist.x = (cub3d->player.pos.x - map->x) * deltd->x;
	else
		side_dist.x = (map->x + 1.0 - cub3d->player.pos.x) * deltd->x;
	if (rayd->y < 0)
		side_dist.y = (cub3d->player.pos.y - map->y) * deltd->y;
	else
		side_dist.y = (map->y + 1.0 - cub3d->player.pos.y) * deltd->y;
	return (side_dist);
}
