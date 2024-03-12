/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ansulist <ansulist@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 23:43:27 by ansulist          #+#    #+#             */
/*   Updated: 2024/03/07 16:23:47 by ansulist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_wcalc(t_cub3d *cub, t_racalc *rc, t_draw_wcalc *dc, t_image *tx)
{
	dc->line_height = (int)(WINDOW_SIZE_Y / rc->distance_to_wall);
	dc->draw_start = -dc->line_height / 2 + WINDOW_SIZE_Y / 2;
	if (dc->draw_start < 0)
		dc->draw_start = 0;
	dc->draw_end = dc->line_height / 2 + WINDOW_SIZE_Y / 2;
	if (dc->draw_end >= WINDOW_SIZE_Y)
		dc->draw_end = WINDOW_SIZE_Y - 1;
	if (rc->side == 0)
		dc->wall_x = cub->player.pos.y
			+ rc->distance_to_wall * rc->ray_direction.y;
	else
		dc->wall_x = cub->player.pos.x
			+ rc->distance_to_wall * rc->ray_direction.x;
	dc->wall_x -= floor(dc->wall_x);
	dc->step = 1.0 * tx->height / dc->line_height;
	dc->texture_pos = (dc->draw_start - WINDOW_SIZE_Y / 2
			+ dc->line_height / 2) * dc->step;
}

void	draw_wall(t_cub3d *cub3d, t_racalc *rc, t_image *texture)
{
	t_draw_wcalc	dc;
	int				i;
	int				color;
	int				texture_y;

	pick_texture(cub3d, rc, texture);
	draw_wcalc(cub3d, rc, &dc, texture);
	texture->tex_x = (int)(dc.wall_x * (float)texture->width);
	if (rc->side == 0 && rc->ray_direction.x > 0)
		texture->tex_x = texture->width - texture->tex_x - 1;
	if (rc->side == 1 && rc->ray_direction.y < 0)
		texture->tex_x = texture->width - texture->tex_x - 1;
	color = 0;
	i = dc.draw_start;
	while (i < dc.draw_end)
	{
		texture_y = (int)dc.texture_pos & (texture->height - 1);
		color = get_image_pixel(texture, texture->tex_x, texture_y);
		my_mlx_pixel_put(&cub3d->image, rc->x, i, color);
		dc.texture_pos += dc.step;
		i++;
	}
}

void	cast_one_ray(t_cub3d *cub3d, int x, t_image *texture)
{
	t_racalc	rc;

	init_racalc(cub3d, x, &rc);
	check_wall_hit(cub3d, &rc);
	calculate_distance_to_wall(&rc);
	draw_wall(cub3d, &rc, texture);
}

void	raycast(t_cub3d *cub3d, t_image *texture)
{
	int	x;

	x = 0;
	while (x < WINDOW_SIZE_X)
	{
		cast_one_ray(cub3d, x, texture);
		x++;
	}
}
