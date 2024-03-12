/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ansulist <ansulist@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 17:04:48 by ansulist          #+#    #+#             */
/*   Updated: 2024/03/07 17:22:46 by ansulist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// Write a pixel inside of the image
void	my_mlx_pixel_put(t_image *data, int x, int y, int color)
{
	char	*dst;

	dst = data->address + (y * data->size_line
			+ x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

// just to put black for the background
void	draw_cieling(t_cub3d *cub3d, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < WINDOW_SIZE_Y / 2)
	{
		j = 0;
		while (j < WINDOW_SIZE_X)
			my_mlx_pixel_put(&cub3d->image, j++, i, color);
		++i;
	}
	mlx_put_image_to_window(cub3d->mlx, cub3d->win, cub3d->image.img, 0, 0);
	return ;
}

void	draw_floor(t_cub3d *cub3d, int color)
{
	int	i;
	int	j;

	i = WINDOW_SIZE_Y / 2;
	while (i < WINDOW_SIZE_Y)
	{
		j = 0;
		while (j < WINDOW_SIZE_X)
			my_mlx_pixel_put(&cub3d->image, j++, i, color);
		++i;
	}
	mlx_put_image_to_window(cub3d->mlx, cub3d->win, cub3d->image.img, 0, 0);
	return ;
}

// Make all the pixels of the image black
void	reset_image(t_cub3d *cub3d)
{
	int	i;
	int	j;

	i = 0;
	while (i < WINDOW_SIZE_Y)
	{
		j = 0;
		while (j < WINDOW_SIZE_X)
			my_mlx_pixel_put(&cub3d->image, j++, i, 0);
		++i;
	}
	mlx_put_image_to_window(cub3d->mlx, cub3d->win,
		cub3d->image.img, 0x000000, 0);
	return ;
}

int	get_image_pixel(t_image *text, int x, int y)
{
	unsigned int	colour;
	char			*dst;

	if (y <= 0)
	{
		y = 0;
	}
	dst = text->address + (y * text->size_line
			+ (x * (text->bits_per_pixel / 8)));
	colour = *(unsigned int *)dst;
	return (colour);
}
