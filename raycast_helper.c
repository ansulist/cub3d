/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_helper.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ansulist <ansulist@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 07:18:42 by ansulist          #+#    #+#             */
/*   Updated: 2024/03/07 17:24:04 by ansulist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_wall_hit(t_cub3d *cub3d, t_racalc *rc)
{
	bool	hit;

	hit = 0;
	while (hit == 0)
	{
		if (rc->side_dist.x < rc->side_dist.y)
		{
			rc->side_dist.x += rc->delta_dist.x;
			rc->map.x += rc->step.x;
			rc->side = 0;
		}
		else
		{
			rc->side_dist.y += rc->delta_dist.y;
			rc->map.y += rc->step.y;
			rc->side = 1;
		}
		if (rc->map.y < 0 || rc->map.x < 0
			|| cub3d->map.blocs[(int)(rc->map.y)][(int)(rc->map.x)] == '1')
			hit = 1;
	}
}

void	init_racalc(t_cub3d *cub, int x, t_racalc *rc)
{
	rc->x = x;
	rc->camera_x = 2 * rc->x / (float)WINDOW_SIZE_X - 1;
	rc->ray_direction = calculate_ray_direction(cub, rc->camera_x);
	rc->delta_dist = calculate_delta_distance(&rc->ray_direction);
	rc->step = calculate_step(&rc->ray_direction);
	rc->map.x = (int)cub->player.pos.x;
	rc->map.y = (int)cub->player.pos.y;
	rc->side_dist = calcsid(cub, &rc->ray_direction, &rc->map, &rc->delta_dist);
	rc->side = 0;
}

void	calculate_distance_to_wall(t_racalc *rc)
{
	if (rc->side == 0)
		rc->distance_to_wall = rc->side_dist.x - rc->delta_dist.x;
	else
		rc->distance_to_wall = rc->side_dist.y - rc->delta_dist.y;
}

void	pick_texture(t_cub3d *cub3d, t_racalc *rc, t_image *texture)
{
	if (rc->side == 0)
	{
		if (rc->ray_direction.x < 0)
			*texture = cub3d->text[E_TEXT];
		else
			*texture = cub3d->text[W_TEXT];
	}
	else
	{
		if (rc->ray_direction.y < 0)
			*texture = cub3d->text[S_TEXT];
		else
			*texture = cub3d->text[N_TEXT];
	}
}
